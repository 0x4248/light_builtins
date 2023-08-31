# Light builtins's (Python version)
# cat - concatenate files and print on the standard output
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/lewisevans2007/light_builtins
# Licence: GNU General Public License v3.0
# By: Lewis Evans

import os
import sys

def main(args):
    if len(args) == 0:
        print("cat: missing operand")
        return 1
    for arg in args:
        if os.path.isfile(arg):
            with open(arg, "r") as file:
                print(file.read())
        else:
            print("cat: " + arg + ": No such file or directory")
            return 1
    return 0

if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))