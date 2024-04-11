#!/usr/bin/env python3
# Light builtins's (Python version)
# date - show the date and time
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/0x4248/light_builtins
# Licence: GNU General Public License v3.0
# By: 0x4248

import sys
import datetime


def main(args):
    date_time = datetime.datetime.now()
    print(date_time)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
