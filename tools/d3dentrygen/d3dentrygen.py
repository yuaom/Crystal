import sys
import os
import argparse

# Clang Imports
import clang.cindex
from clang.cindex import CursorKind
from clang.cindex import TypeKind


def parse_ddi_table(cursor):
    print("Parsing DDI Table '%s'..." % cursor.spelling)
    for child in cursor.get_children():
        print("Cursor @ line %d" % child.location.line)
        print("   %s (%s)" % (child.spelling, child.type.spelling))


def parse_translation_unit(cursor, file):
    for child in cursor.get_children():
        # Only parse the main file
        if(child.location.file.name != cursor.spelling):
            continue
        print("Cursor @ line %d" % child.location.line)
        if(child.kind == CursorKind.STRUCT_DECL and child.spelling in ['D3D11_1DDI_DEVICEFUNCS']):
            parse_ddi_table(child)
        elif(child.kind == CursorKind.TYPEDEF_DECL and child.spelling == "APIENTRY"):
            print(child.spelling)


def parse_header(file, wdk_path):
    index = clang.cindex.Index.create()

    include = '--include=%s' % r'Windows.h'
    search_path = '--include-directory=%s' % wdk_path

    translation_unit = index.parse(file, [
        '--language=c',
        '-DWIN32_LEAN_AND_MEAN=1',
        include,
        search_path
    ])

    parse_translation_unit(translation_unit.cursor, file)


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
    parser.add_argument('--output', metavar='PATH', required=False,
                        help='Define output path. Default cwd\output')
    args = parser.parse_args()

    headers_to_parse = [
        os.path.join('um', 'd3d10umddi.h')
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
            parse_header(header_path, args.wdk)


if __name__ == "__main__":
    main()
