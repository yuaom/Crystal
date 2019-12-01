import sys
import os
import argparse
import re
from mako.template import Template

# Clang Imports
import clang.cindex
from clang.cindex import CursorKind
from clang.cindex import TypeKind


class ParseException(Exception):
    pass


class DDIEntrypoint:
    def __init__(self, name, params):
        self.name = name
        self.params = params


def get_parameter_name(type_string, suggested):
    if(suggested != ''):
        return suggested

    type_string = type_string.replace("const ", "")
    type_string = type_string.replace("struct ", "")

    # Handles first since the most common
    result = re.match(".*D3D1[01]DDI_H(?P<name>.*).*", type_string)
    if(result != None):
        return 'h' + result.group('name').lower().capitalize()

    # Calc/Creates next
    result = re.match(".*D3D1[01]DDIARG_(?P<name>.*).*", type_string)
    if(result != None):
        return 'p' + result.group('name').lower().capitalize()

    # Primitive types second
    primitive_types = ['UINT', 'DWORD', 'void*',
                       'INT', 'FLOAT', 'BOOL', 'LPSTR']
    for prim_type in primitive_types:
        if(prim_type in type_string):
            return "arg"

    # Custom names last
    custom_names = {
        'DXGI_FORMAT': 'format',
        'D3D10_DDI_BOX*': 'pBox',
        'D3D10_DDI_MAP': 'map',
        'D3D10DDI_COUNTER_INFO*': 'pCounterInfo',
        'D3D10DDI_QUERY': 'query',
        'D3D10DDI_COUNTER_TYPE*': 'pCounterType',
        'D3D10DDI_MAPPED_SUBRESOURCE*': 'pSubresource',
        'D3D10_DDI_PRIMITIVE_TOPOLOGY': 'topology',
        'D3D10_DDI_VIEWPORT*': 'pViewport',
        'D3D10_DDI_RECT*': 'pRect',
        'D3D10_DDI_SAMPLER_DESC*': 'pSamplerDesc',
        'D3D11_1DDI_DEVICEFUNCS*': 'pFuncs',
        'D3D10_DDI_DEPTH_STENCIL_DESC*': 'pDepthStencilDesc',
        'D3D11_1_DDI_BLEND_DESC*': 'pBlendDesc',
        'D3D11_1_DDI_RASTERIZER_DESC*': 'pRasterizerDesc',
        'D3D11_1DDIARG_STAGE_IO_SIGNATURES*': 'pIOSignatures',
        'D3D11_1DDIARG_TESSELLATION_IO_SIGNATURES*': 'pIOSignatures'
    }
    for custom_name, result in custom_names.items():
        if custom_name == type_string:
            return result

    raise ParseException(
        "Unable to translate argument name for %s" % type_string)


def parse_ddi_table(args, cursor, pfnCursors, ddi_entrypoints):
    print("  Found DDI Table '%s'..." % cursor.spelling)
    for child in cursor.get_children():
        try:
            print("    %s (%s)" % (child.spelling, child.type.spelling))
            function_name = child.spelling[3:]

            type_cursor = pfnCursors[child.type.spelling]
            type_typedef_spelling = type_cursor.underlying_typedef_type.spelling

            if(type_cursor.underlying_typedef_type.kind != TypeKind.POINTER):
                raise ParseException(
                    "%s expected to be a pointer type!" % child.type.spelling)

            # Generate parameter list
            params = []
            arg_num = 0
            for typedef_parm_cursor in type_cursor.get_children():
                if(typedef_parm_cursor.kind == CursorKind.PARM_DECL):
                    param_type = typedef_parm_cursor.type.spelling
                    param_type = param_type.replace(" *", "*")

                    param_name = get_parameter_name(
                        param_type, typedef_parm_cursor.spelling)

                    # append argument number to native types
                    if param_name == 'arg':
                        param_name = param_name + str(arg_num)
                        arg_num = arg_num + 1

                    params.append((param_type, param_name))

            # Append entrypoint
            ddi_entrypoints.append(DDIEntrypoint(function_name, params))
        except KeyError:
            raise ParseException("Error! Unable to find type information for %s!" %
                                 child.type.spelling)


def parse_translation_unit(args, cursor, file, tables_to_parse, ddi_entrypoints):
    # cached pfn* typedef cursors
    pfnCursors = {}

    for child in cursor.get_children():
        # Only parse the main file
        if(child.location.file.name != cursor.spelling):
            continue
        if(child.kind == CursorKind.STRUCT_DECL and child.spelling in tables_to_parse):
            parse_ddi_table(args, child, pfnCursors, ddi_entrypoints)
        elif(child.kind == CursorKind.TYPEDEF_DECL and child.spelling[:3] == "PFN"):
            pfnCursors[child.spelling] = child


def parse_header(file, args, tables_to_parse, ddi_entrypoints):
    success = True

    index = clang.cindex.Index.create()

    include = '--include=%s' % r'Windows.h'
    search_path = '--include-directory=%s' % args.wdk

    translation_unit = index.parse(file, [
        '--language=c',
        '-DWIN32_LEAN_AND_MEAN=1',
        include,
        search_path
    ])

    try:
        parse_translation_unit(
            args, translation_unit.cursor, file, tables_to_parse, ddi_entrypoints)
    except ParseException as e:
        print(e)
        success = False

    return success


def configure_environment(args, headers):
    wdk_found = False
    headers_found = False

    # Look for WDK
    print("  Looking for WDK in %s... " % args.wdk, end='')
    if(os.path.exists(args.wdk)):
        print("found!")
        wdk_found = True
    else:
        print("not found!")
        wdk_found = False

    # Look for headers in WDK
    if(wdk_found):
        for header in headers:
            full_path = os.path.join(args.wdk, header)
            print("  Looking for %s..." % full_path, end='')
            if(os.path.exists(full_path)):
                print("found!")
                headers_found = True
            else:
                print("not found!")
                headers_found = False
                break

    return wdk_found and headers_found


def configure_clang():
    configured = False
    tools_dir = os.path.sep.join(sys.path[0].split(os.path.sep)[:-1])
    search_paths = [
        os.path.join(tools_dir, 'llvm', '9.0.0', 'bin'),
        os.path.join(os.getcwd())
    ]
    for path in search_paths:
        print("  Looking for libclang.dll in %s..." % path, end='')
        full_path = os.path.join(path, 'libclang.dll')
        if(os.path.exists(full_path)):
            clang.cindex.Config.set_library_path(path)
            print(" found!")
            configured = True
            break
        else:
            print(" not found.")
    return configured


def write_template(template_file, entries):
    template = Template(filename=template_file)
    print(template.render(entries=entries))


def main():
    success = True

    parser = argparse.ArgumentParser(
        description='Parse D3D11/12 DDI header files to produce stubbed entry-points.')
    parser.add_argument('--wdk', metavar='PATH',
                        required=True, help='Define WDK path')
    parser.add_argument('--output', metavar='PATH', default=os.path.join(os.getcwd(), 'output'), required=False,
                        help='Define output path. Default cwd\\output')
    parser.add_argument('--debug', default=False, action="store_true")
    args = parser.parse_args()

    headers_to_parse = [
        os.path.join('um', 'd3d10umddi.h')
    ]

    tables_to_parse = [
        'D3D11_1DDI_DEVICEFUNCS'
    ]

    print("Checking environment...")
    if(success):
        success = configure_environment(args, headers_to_parse)
    if(success):
        success = configure_clang()

    if(not success):
        print("Check failed!")
    else:
        print("")

    if(success):
        for header in headers_to_parse:
            header_path = os.path.join(args.wdk, header)
            print("Parsing %s..." % header_path)

            ddi_entrypoints = []

            success = parse_header(
                header_path, args, tables_to_parse, ddi_entrypoints)

            if(not success):
                break

            write_template('template_ddi.cpp', ddi_entrypoints)


if __name__ == "__main__":
    main()
