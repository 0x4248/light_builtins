# Light builtins's (C version)
# C build script
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/0x4248/light_builtins
# Licence: GNU General Public License v3.0

echo "Cleaning old build"
rm -rf bin/c/*
rm -rf bin/*
echo "Creating build dir's"
mkdir -p bin/c
mkdir -p bin
echo "Compiling C builtins"
gcc -g -Wall -std=c2x src/c/pwd.c -o bin/c/pwd
gcc -g -Wall -std=c2x src/c/echo.c -o bin/c/echo
gcc -g -Wall -std=c2x src/c/mkdir.c -o bin/c/mkdir
gcc -g -Wall -std=c2x src/c/rmdir.c -o bin/c/rmdir
gcc -g -Wall -std=c2x src/c/rm.c -o bin/c/rm
gcc -g -Wall -std=c2x src/c/cp.c -o bin/c/cp
gcc -g -Wall -std=c2x src/c/mv.c -o bin/c/mv
gcc -g -Wall -std=c2x src/c/ls.c -o bin/c/ls
gcc -g -Wall -std=c2x src/c/cat.c -o bin/c/cat
echo "Done"