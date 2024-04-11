#!/usr/bin/env python3
# Light builtins's (Python version)
# echo - print arguments to the standard output
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/0x4248/light_builtins
# Licence: GNU General Public License v3.0
# By: 0x4248

import os
import sys


def main(args):
    print(" ".join(args))
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
