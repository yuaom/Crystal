import argparse
import os
import re
import sys


def parse(args, path):
    success = True

    re_filename = re.compile("nc-.*\.md")
    re_typedef = re.compile("#{1} (\w*).*")
    re_argname_section = re.compile("### -param (\w*).*")
    re_argname_in = re.compile("\*(\w*)\*.*")
    rg_arg = re.compile("Arg\d*")

    ddilist = []

    md_files = [os.path.join(path, file) for file in os.listdir(
        path) if re_filename.match(file) != None]
    for md in md_files:
        print("Parsing %s..." % os.path.basename(md))
        lines = []
        try:
            with open(md) as f:
                lines = [line.strip()
                         for line in f.readlines() if line.strip() != ""]
        except UnicodeDecodeError as e:
            print("Error: %s" % str(e))
            success = False
            break

        backup = ""
        typedef = ""
        for line in lines:
            # find pfn
            match = re_typedef.match(line)
            if(match != None):
                # resolve backup from previous section
                if(backup != ""):
                    ddilist[-1].append(argname)
                    backup = ""

                typedef = match.group(1)
                ddilist.append([typedef])
                continue

            # look for argument_section
            match = re_argname_section.match(line)
            if(match != None):
                # resolve backup from previous section
                if(backup != ""):
                    ddilist[-1].append(argname)
                    backup = ""

                argname = match.group(1)
                match = rg_arg.match(argname)
                if(match == None):
                    ddilist[-1].append(argname)
                    continue
                else:
                    backup = argname

            # if in argument section, look for bolded, [in] name
            match = re_argname_in.match(line)
            if(match != None):
                argname = match.group(1)
                if(backup != ''):
                    ddilist[-1].append(argname)
                    backup = ""
                else:
                    ddilist[-1][-1] = argname
                continue

        # resolve backup from previous section
        if(backup != ""):
            ddilist[-1].append(argname)
            backup = ""

    out_file = os.path.join(args.output, "argnames.csv")
    if(not os.path.exists(args.output)):
        os.makedirs(args.output)
    with open(out_file, "w+") as f:
        for ddi in ddilist:
            f.write(','.join(ddi))
            f.write('\n')

    return success


def main():
    parser = argparse.ArgumentParser(
        description='Parses Microsoft\'s windows-driver-docs-ddi github repository for DDI argument names.')
    parser.add_argument('--path', metavar='PATH',
                        required=True, help='Cloned or downloaded respository path.')
    parser.add_argument('--output', metavar='PATH', default=os.path.join(sys.path[0], 'output'), required=False,
                        help='Define output path. Default scriptdir\\output')
    args = parser.parse_args()

    sub_directories = [
        os.path.join(args.path, "wdk-ddi-src", "content", "d3d10umddi")
    ]

    success = True
    for subdir in sub_directories:
        success = parse(args, subdir)
        if not success:
            break

    if success:
        print("Finished.")
    else:
        print("Failed.")


if __name__ == "__main__":
    main()
