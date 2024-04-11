#!/usr/bin/env python3
# Light builtins's (Python version)
# ls - list files in a directory
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/0x4248/light_builtins
# Licence: GNU General Public License v3.0
# By: 0x4248

import os
import sys


def main(args):
    if len(args) == 0:
        args = [os.getcwd()]
    for arg in args:
        if os.path.isdir(arg):
            for file in os.listdir(arg):
                if os.path.isdir(arg + "/" + file):
                    print(file + "/")
                else:
                    print(file)
        else:
            print(arg)


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
