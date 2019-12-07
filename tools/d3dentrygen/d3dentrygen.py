import sys
import os
import argparse
import re
from mako.template import Template

# Clang Imports
import clang.cindex
from clang.cindex import CursorKind
from clang.cindex import TypeKind


class ParseContext:
    def __init__(self, input_file, output_directory, output_filemap, table, template_name):
        self.filename = input_file
        self.table = table
        self.template = template_name
        self.entrypoints = {}
        self.output_directory = output_directory
        self.output_filemap = output_filemap

    def add_entrypoint(self, entry):
        # Find matching output file
        output_file = "umd_ddi.cpp"
        for entry_expression, filename in self.output_filemap.items():
            if(re.match(entry_expression, entry.name) != None):
                output_file = filename
                break

        # Append entry-point to that file's list
        if output_file not in self.entrypoints.keys():
            self.entrypoints[output_file] = [entry]
        else:
            self.entrypoints[output_file].append(entry)

    def write_template(self):
        for output_file in self.entrypoints.keys():
            template = Template(filename=self.template)
            try:
                render = template.render(
                    table_name=self.table,
                    entries=self.entrypoints[output_file])

                output_full = os.path.join(self.output_directory, output_file)
                output_directory = os.path.dirname(output_full)
                if(not os.path.exists(output_directory)):
                    os.makedirs(output_directory)

                with open(output_full, "w") as file:
                    print(render, file=file)
            except Exception as e:
                print(e)


class ParseException(Exception):
    pass


class DDIEntrypoint:
    def __init__(self, return_type, name, params):
        self.return_type = return_type
        self.name = name
        self.params = params


def get_parameter_name(type_string, suggested):
    if(suggested != ''):
        return suggested

    type_string = type_string.replace("const ", "")
    type_string = type_string.replace("struct ", "")

    # Handles first since the most common
    result = re.match(".*D3D1[01]DDI_H(?P<name>\w*).*", type_string)
    if(result != None):
        return 'h' + result.group('name').lower().capitalize()

    # Calc/Creates next
    result = re.match(".*D3D1[01]DDIARG_(?P<name>\w*).*", type_string)
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


def parse_ddi_table(args, context, cursor, pfnCursors):
    print("  Found DDI Table '%s'..." % cursor.spelling)
    for child in cursor.get_children():
        try:
            if(args.debug):
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
                    param_type = ""
                    param_name = ""
                    param_suffix = ""

                    # Reconstruct constant array
                    if(typedef_parm_cursor.type.kind == TypeKind.CONSTANTARRAY):
                        param_type = typedef_parm_cursor.type.element_type.spelling
                        param_name = get_parameter_name(
                            param_type,
                            typedef_parm_cursor.spelling)
                        param_suffix = "[%d]" % typedef_parm_cursor.type.element_count
                    else:
                        param_type = typedef_parm_cursor.type.spelling
                        param_type = param_type.replace(" *", "*")
                        param_name = get_parameter_name(
                            param_type, typedef_parm_cursor.spelling)

                    params.append([param_type, param_name, param_suffix])

            # Deduplicate params
            duplicates = {}
            for param in params:
                key = param[1]
                if key in duplicates.keys():
                    count = duplicates[key]
                    if(count == 0):
                        duplicates[key] = 2
                    else:
                        duplicates[key] = count + 1
                else:
                    duplicates[key] = 0
            if len(duplicates) > 1:
                for param in reversed(params):
                    key = param[1]
                    count = duplicates[key]
                    if count >= 1:
                        param[1] = param[1] + str(count)
                        duplicates[key] = count - 1

            # Get return type
            return_type = "VOID"
            if(child.type.kind == TypeKind.TYPEDEF):
                for return_type_child in type_cursor.get_children():
                    if (return_type_child.kind == CursorKind.TYPE_REF):
                        return_type = return_type_child.spelling
                        break

            # Append entrypoint
            context.add_entrypoint(DDIEntrypoint(
                return_type, function_name, params))

        except KeyError:
            raise ParseException("Error parsing %s!" % child.type.spelling)


def parse_translation_unit(args, context, cursor):
    # cached pfn* typedef cursors
    pfnCursors = {}

    for child in cursor.get_children():
        # Only parse the main file
        if(child.location.file.name != cursor.spelling):
            continue
        if(child.kind == CursorKind.STRUCT_DECL and child.spelling == context.table):
            parse_ddi_table(args, context, child, pfnCursors)
        elif(child.kind == CursorKind.TYPEDEF_DECL and child.spelling[:3] == "PFN"):
            pfnCursors[child.spelling] = child


def parse_header(args, context):
    success = True

    index = clang.cindex.Index.create()

    include = '--include=%s' % r'Windows.h'
    search_path = '--include-directory=%s' % args.wdk

    try:
        translation_unit = index.parse(context.filename, [
            '--language=c',
            '-DWIN32_LEAN_AND_MEAN=1',
            include,
            search_path
        ])

        parse_translation_unit(args, context, translation_unit.cursor)
    except (clang.cindex.TranslationUnitLoadError, ParseException) as e:
        print(e)
        success = False

    return success


def configure_environment(args, contexts):
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
        for parse_context in contexts:
            print("  Looking for %s..." % parse_context.filename, end='')
            if(os.path.exists(parse_context.filename)):
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

    filemap = {
        "DefaultConstantBufferUpdateSubresourceUP": "umd_ddi_draw.cpp"
    }

    contexts = [
        ParseContext(os.path.join(args.wdk, 'um', 'd3d10umddi.h'),
                     args.output,
                     filemap,
                     'D3D11_1DDI_DEVICEFUNCS',
                     os.path.join(sys.path[0], 'ddi.template'))
    ]

    print("Checking environment...")
    if(success):
        success = configure_environment(args, contexts)
    if(success):
        success = configure_clang()

    if(not success):
        print("Check failed!")
    else:
        print("")

    if(success):
        for context in contexts:
            print("Parsing %s..." % context.filename)

            success = parse_header(args, context)

            if(not success):
                break

            context.write_template()


if __name__ == "__main__":
    main()
