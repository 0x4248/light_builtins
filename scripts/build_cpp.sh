# Light builtins's
# C++ build script
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/lewisevans2007/light_builtins
# Licence: GNU General Public License v3.0

rm -rf bin/c/*
rm -rf bin/*
mkdir -p bin/c
mkdir -p bin
g++ -g -Wall -std=c++17 src/ls.cpp -o bin/ls
g++ -g -Wall -std=c++17 src/pwd.cpp -o bin/pwd
g++ -g -Wall -std=c++17 src/cat.cpp -o bin/cat
g++ -g -Wall -std=c++17 src/echo.cpp -o bin/echo
g++ -g -Wall -std=c++17 src/mkdir.cpp -o bin/mkdir
g++ -g -Wall -std=c++17 src/rmdir.cpp -o bin/rmdir
g++ -g -Wall -std=c++17 src/rm.cpp -o bin/rm
g++ -g -Wall -std=c++17 src/cp.cpp -o bin/cp
g++ -g -Wall -std=c++17 src/mv.cpp -o bin/mv