import sys
import os
import argparse
import re
from mako.template import Template
import filemap

# Clang Imports
import clang.cindex
from clang.cindex import CursorKind
from clang.cindex import TypeKind

argument_names = {}


class Templates:
    def __init__(self, ddi_cpp, filltable_h, filltable_cpp):
        self.ddi_cpp = ddi_cpp
        self.filltable_h = filltable_h
        self.filltable_cpp = filltable_cpp


class ParseContext:
    def __init__(self, input_file, output_directory, output_filemap, table, template):
        self.filename = input_file
        self.table = table
        self.template = template
        self.entrypoints = {}
        self.output_directory = output_directory
        self.output_filemap = output_filemap

    def add_entrypoint(self, entry):
        # Find matching output file
        output_file = ""
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
        for entry_list in self.entrypoints.values():
            entry_list = entry_list.sort()

        for output_file in self.entrypoints.keys():
            template = Template(filename=self.template.ddi_cpp)
            try:
                output_full = os.path.join(self.output_directory, output_file)

                print("    Generating %d entries into %s..." %
                      (len(self.entrypoints[output_file]), output_full))

                render = template.render(
                    table_name=self.table,
                    entries=self.entrypoints[output_file])
                ParseContext.write_template_render_to_file(render, output_full)

            except Exception as e:
                print(e)

        # Output umd_ddi.cpp
        try:
            output_full = os.path.join(self.output_directory, "umd_ddi.cpp")
            print("    Generating %s..." % output_full)
            template = Template(filename=self.template.filltable_cpp)
            render = template.render(
                table_name=self.table,
                entry_lists=self.entrypoints.values())
            ParseContext.write_template_render_to_file(render, output_full)
        except Exception as e:
            print(e)

        # Output umd_ddi.h
        try:
            output_full = os.path.join(self.output_directory, "umd_ddi.h")
            print("    Generating %s..." % output_full)
            template = Template(filename=self.template.filltable_h)
            render = template.render(
                table_name=self.table,
                entry_lists=self.entrypoints.values())
            ParseContext.write_template_render_to_file(render, output_full)
        except Exception as e:
            print(e)

    @staticmethod
    def write_template_render_to_file(str, filename):
        output_directory = os.path.dirname(filename)
        if(not os.path.exists(output_directory)):
            os.makedirs(output_directory)

        with open(filename, "a+") as file:
            print(str, file=file)


class ParseException(Exception):
    pass


class DDIEntrypoint:
    def __init__(self, return_type, name, params):
        self.return_type = return_type
        self.name = name
        self.params = params
        self.priority = -1
        self.update_priority()

    def update_priority(self):
        # Create/Destroy/Opens always first
        if(self.name.find("Create") != -1):
            if("Vertex" in self.name):
                self.priority = 0
            elif("Hull" in self.name):
                self.priority = 1
            elif("Domain" in self.name):
                self.priority = 2
            elif("Geometry" in self.name):
                self.priority = 3
            elif("Pixel" in self.name):
                self.priority = 4
            elif("Pixel" in self.name):
                self.priority = 5
            else:
                self.priority = 6
        elif(self.name.find("Destroy") != -1):
            self.priority = 7
        elif(self.name.find("Open") != -1):
            self.priority = 8

        # I prefer pipeline order of shader related entry-points
        elif(self.name.find("Vs") != -1 or self.name.find("VertexShader") != -1):
            self.priority = 10
        elif(self.name.find("Hs") != -1 or self.name.find("HullShader") != -1):
            self.priority = 11
        elif(self.name.find("Ds") != -1 or self.name.find("DomainShader") != -1):
            self.priority = 12
        elif(self.name.find("Gs") != -1 or self.name.find("GeometryShader") != -1):
            self.priority = 13
        elif(self.name.find("Ps") != -1 or self.name.find("PixelShader") != -1):
            self.priority = 14
        elif(self.name.find("Cs") != -1 or self.name.find("ComputeShader") != -1):
            self.priority = 15

        # Everything else I don't care, so sort by name
        else:
            self.priority = 200

    def __lt__(self, rh):
        if(self.priority == rh.priority):
            return self.name < rh.name
        else:
            return self.priority < rh.priority

    def __str__(self):
        return self.name


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

    # Match/Convert DXGI types
    result = re.match("DXGI(1_6_1)?_DDI_ARG_(?P<name>.*)\*", type_string)
    if(result != None):
        name = result.group('name').lower().capitalize()
        j = len(name)
        i = 0
        while i < j:
            if(name[i] == '_'):
                name = name[:i] + name[i+1:].capitalize()
                j = len(name)
            i = i + 1
        return 'p' + name

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
            function_name = child.spelling[3:]

            if('Reserved' in function_name):
                continue

            type_cursor = None
            return_type = 'VOID'

            # if the child is a typedef, look up the typedef cursor
            # and make sure the typedef is a pointer type
            if(child.type.kind == TypeKind.TYPEDEF):
                type_cursor = pfnCursors[child.type.spelling]

                if(type_cursor.underlying_typedef_type.kind != TypeKind.POINTER):
                    raise ParseException(
                        "%s expected to be a pointer type!" % child.type.spelling)

                # get the return type
                for return_type_child in type_cursor.get_children():
                    if (return_type_child.kind == CursorKind.TYPE_REF):
                        return_type = return_type_child.spelling
                        break

            # if the type is a pointer, then use the child type cursor directly
            elif(child.type.kind == TypeKind.POINTER):
                type_cursor = child
            else:
                raise ParseException("Unsupported child type.")

            # Generate parameter list
            params = []
            arg_num = -1
            for typedef_parm_cursor in type_cursor.get_children():
                # the first child might be the return type for function pointers
                if(typedef_parm_cursor.kind == CursorKind.TYPE_REF):
                    return_type = typedef_parm_cursor.spelling
                # otherwise the children for typedefs will omit the return type
                # and immediately start iterating over function arguments
                elif(typedef_parm_cursor.kind == CursorKind.PARM_DECL):
                    arg_num = arg_num + 1
                    param_type = ""
                    param_name = ""
                    param_suffix = ""

                    # Reconstruct constant array
                    if(typedef_parm_cursor.type.kind == TypeKind.CONSTANTARRAY):
                        param_type = typedef_parm_cursor.type.element_type.spelling
                        param_name = argument_names[child.type.spelling][arg_num]
                        param_suffix = "[%d]" % typedef_parm_cursor.type.element_count
                    else:
                        param_type = typedef_parm_cursor.type.spelling
                        param_type = param_type.replace(" *", "*")

                        pfnName = child.type.spelling
                        if pfnName in argument_names.keys():
                            param_name = argument_names[pfnName][arg_num]

                        if param_name == "" or re.match("[Aa]rg\d*", param_name) != None:
                            param_name = get_parameter_name(
                                param_type,
                                typedef_parm_cursor.spelling)

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

    # Look for arg names
    print("  Looking for argument naming hint file %s... " %
          args.argnames, end='')
    if(os.path.exists(args.argnames)):
        print("found!")
    else:
        print("not found!")
        print("  Warning: could not find argnames file %s." % args.argnames)
        print("  Warning: Script will use fallback naming mechanism.")

    return wdk_found and headers_found


def clean_output(contexts):
    delete_count = 0
    for parse_context in contexts:
        print("  %s..." % parse_context.table, end="")
        ddi_files = ['umd_ddi.h', 'umd_ddi.cpp']

        for outfile in parse_context.output_filemap.values():
            ddi_files.append(outfile)

        for ddi_file in ddi_files:
            full_path = os.path.join(parse_context.output_directory, ddi_file)
            if(os.path.exists(full_path)):
                try:
                    os.remove(full_path)
                    delete_count = delete_count + 1
                except:
                    print("\n  Warning: unable to delete %s." % ddi_file)
        print(" finished! %d files deleted." % delete_count)


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
    parser.add_argument('--output', metavar='PATH', default=os.path.join(sys.path[0], 'output'), required=False,
                        help='Define output path. Default scriptdir\\output.')
    parser.add_argument('--argnames', metavar='PATH', default=os.path.join(sys.path[0], 'output', 'argnames.csv'), required=False,
                        help='Argument name CSV file to use as name hints. Output from namegen.py. Default scriptdir\\output.')
    args = parser.parse_args()

    contexts = [
        ParseContext(os.path.join(args.wdk, 'um', 'd3d10umddi.h'),
                     args.output,
                     filemap.filemap["D3DWDDM1_3DDI_DEVICEFUNCS"],
                     'D3DWDDM1_3DDI_DEVICEFUNCS',
                     Templates(
                         os.path.join(
                             sys.path[0], 'templates\\ddi.cpp.template'),
                         os.path.join(
                             sys.path[0], 'templates\\filltable.h.template'),
                         os.path.join(
                             sys.path[0], 'templates\\filltable.cpp.template'))),
        ParseContext(os.path.join(args.wdk, 'um', 'dxgiddi.h'),
                     args.output,
                     filemap.filemap["DXGI1_6_1_DDI_BASE_FUNCTIONS"],
                     'DXGI1_6_1_DDI_BASE_FUNCTIONS',
                     Templates(
                         os.path.join(
                             sys.path[0], 'templates\\ddi.cpp.template'),
                         os.path.join(
                             sys.path[0], 'templates\\filltable.h.template'),
                         os.path.join(
                             sys.path[0], 'templates\\filltable.cpp.template')))
    ]

    print("Checking environment...")
    if(success):
        success = configure_environment(args, contexts)
    if(success):
        success = configure_clang()

    if(success):
        print("\nCleaning old output...")
        clean_output(contexts)

    if(success):
        try:
            print("\nLoading argument hints... ", end='')
            csvlines = []
            with open(args.argnames) as f:
                csvlines = f.readlines()
            for line in csvlines:
                parts = line.strip().split(',')
                argument_names[parts[0]] = parts[1:]
            print('finished!')
        except Exception as e:
            print('error!')
            print(e)
            success = False

    if(success):
        for context in contexts:
            print("\nParsing %s..." % context.filename)

            success = parse_header(args, context)

            if(not success):
                break

            context.write_template()


if __name__ == "__main__":
    main()
