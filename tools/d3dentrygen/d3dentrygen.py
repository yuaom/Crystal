import sys
import os
import argparse

# Clang Imports
import clang.cindex
from clang.cindex import CursorKind
from clang.cindex import TypeKind


class ParseException(Exception):
    pass


def get_parameter_name(type_string, suggested):
    # Handles first since the most common
    handle_string = "D3D10DDI_H"
    handle_index = type_string.find(handle_string)
    if(handle_index != -1):
        return 'h' + type_string[handle_index+len(handle_string):].lower().capitalize()

    handle_string = "D3D11DDI_H"
    handle_index = type_string.find(handle_string)
    if(handle_index != -1):
        return 'h' + type_string[handle_index+len(handle_string):].lower().capitalize()

    # Calc/Creates next

    # Primitive types second
    primitive_types = ['UINT', 'DWORD', 'void *', 'INT', 'FLOAT', 'BOOL']
    for prim_type in primitive_types:
        if(prim_type in type_string):
            return "arg"

    # Custom names last
    if('D3D10_DDI_BOX *' in type_string):
        return 'pBox'
    if('D3D10_DDI_MAP' in type_string):
        return 'map'
    if('D3D10DDI_MAPPED_SUBRESOURCE *' in type_string):
        return 'pSubresource'
    if('DXGI_FORMAT' in type_string):
        return 'format'
    if('D3D10_DDI_PRIMITIVE_TOPOLOGY' in type_string):
        return 'topology'
    if('D3D10_DDI_VIEWPORT *' in type_string):
        return 'pViewport'
    if('D3D10_DDI_RECT *' in type_string):
        return 'pRect'
    if('D3D11_1DDI_DEVICEFUNCS *' in type_string):
        return 'pFuncs'

    raise ParseException(
        "Unable to translate argument name for %s" % type_string)


def parse_ddi_table(args, cursor, pfnCursors):
    print("  Found DDI Table '%s'..." % cursor.spelling)
    for child in cursor.get_children():
        try:
            print("    %s (%s)" % (child.spelling, child.type.spelling))

            type_cursor = pfnCursors[child.type.spelling]
            type_typedef_spelling = type_cursor.underlying_typedef_type.spelling

            if(type_cursor.underlying_typedef_type.kind != TypeKind.POINTER):
                raise ParseException(
                    "%s expected to be a pointer type!" % child.type.spelling)

            params = []
            for typedef_parm_cursor in type_cursor.get_children():
                if(typedef_parm_cursor.kind == CursorKind.PARM_DECL):
                    param_type = typedef_parm_cursor.type.spelling
                    param_name = get_parameter_name(
                        param_type, typedef_parm_cursor.spelling)
                    params.append(param_type)
                    params.append(param_name)
            if(args.debug):
                print("      %s" % type_typedef_spelling)
                print("      Params = %s" % str(params))
        except KeyError:
            raise ParseException("Error! Unable to find type information for %s!" %
                                 child.type.spelling)


def parse_translation_unit(args, cursor, file, tables_to_parse):
    # cached pfn* typedef cursors
    pfnCursors = {}

    for child in cursor.get_children():
        # Only parse the main file
        if(child.location.file.name != cursor.spelling):
            continue
        if(child.kind == CursorKind.STRUCT_DECL and child.spelling in tables_to_parse):
            parse_ddi_table(args, child, pfnCursors)
        elif(child.kind == CursorKind.TYPEDEF_DECL and child.spelling[:3] == "PFN"):
            pfnCursors[child.spelling] = child


def parse_header(file, args, tables_to_parse):
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
            args, translation_unit.cursor, file, tables_to_parse)
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


def main():
    success = True

    parser = argparse.ArgumentParser(
        description='Parse D3D11/12 DDI header files to produce stubbed entry-points.')
    parser.add_argument('--wdk', metavar='PATH',
                        required=True, help='Define WDK path')
    parser.add_argument('--output', metavar='PATH', default=os.path.join(os.getcwd(), 'output'), required=False,
                        help='Define output path. Default cwd\output')
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
            success = parse_header(header_path, args, tables_to_parse)

            if(not success):
                break


if __name__ == "__main__":
    main()
