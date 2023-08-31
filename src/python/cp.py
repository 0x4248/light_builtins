#!/usr/bin/env python3
# Light builtins's (Python version)
# cp - copy files or directories
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/lewisevans2007/light_builtins
# Licence: GNU General Public License v3.0
# By: Lewis Evans

import os
import sys


def main(args):
    if len(args) < 2:
        print("cp: missing file operand")
        return 1
    if len(args) > 2:
        print("cp: extra operand")
        return 1
    if not os.path.exists(args[0]):
        print("cp: cannot stat '" + args[0] + "': No such file or directory")
        return 1
    if os.path.isdir(args[0]):
        print("cp: omitting directory '" + args[0] + "'")
        return 1

    try:
        with open(args[0], "r") as f:
            data = f.read()
    except:
        print("cp: cannot stat '" + args[0] + "': Permission denied")
        return 1

    try:
        with open(args[1], "w") as f:
            f.write(data)
    except:
        print("cp: cannot stat '" + args[1] + "': Permission denied")
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
