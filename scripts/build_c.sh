# Light builtins's (C version)
# C build script
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/awesomelewis2007/light_builtins
# Licence: GNU General Public License v3.0


rm -rf bin/c/*
rm -rf bin/*
mkdir -p bin/c
mkdir -p bin
gcc -g -Wall -std=c2x src/c/pwd.c -o bin/c/pwd
gcc -g -Wall -std=c2x src/c/echo.c -o bin/c/echo
gcc -g -Wall -std=c2x src/c/mkdir.c -o bin/c/mkdir
gcc -g -Wall -std=c2x src/c/rmdir.c -o bin/c/rmdir