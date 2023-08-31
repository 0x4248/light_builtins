#!/usr/bin/env python3
# Light builtins's (Python version)
# touch - create a file with the current time
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/lewisevans2007/light_builtins
# Licence: GNU General Public License v3.0
# By: Lewis Evans

import os
import sys

def main(args):
    if len(args) < 1:
        print("touch: missing file operand")
        return 1
    if len(args) > 1:
        print("touch: extra operand")
        return 1
    if os.path.exists(args[0]):
        print("touch: cannot create file '" + args[0] + "': File exists")
        return 1
    try:
        with open(args[0], 'w') as f:
            f.write("")
    except:
        print("touch: cannot create file '" + args[0] + "': Permission denied")
        return 1
    return 0

if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))