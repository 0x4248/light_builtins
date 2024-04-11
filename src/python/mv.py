#!/usr/bin/env python3
# Light builtins's (Python version)
# mv - move files or directories
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/0x4248/light_builtins
# Licence: GNU General Public License v3.0
# By: 0x4248

import os
import sys


def main(args):
    if len(args) < 2:
        print("mv: missing file operand")
        return 1
    if len(args) > 2:
        print("mv: extra operand")
        return 1
    if not os.path.exists(args[0]):
        print("mv: cannot stat '" + args[0] + "': No such file or directory")
        return 1
    if os.path.isdir(args[0]):
        print("mv: omitting directory '" + args[0] + "'")
        return 1

    try:
        os.rename(args[0], args[1])
    except:
        print("mv: cannot stat '" + args[1] + "': Permission denied")
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
