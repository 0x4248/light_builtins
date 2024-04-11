# Light builtins's
# C++ build script
# A lightweight repository of useful shell commands
# GitHub: https://www.github.com/0x4248/light_builtins
# Licence: GNU General Public License v3.0

echo "Cleaning old build"
rm -rf bin/c/*
rm -rf bin/*
echo "Creating build dir's"
mkdir -p bin/c
mkdir -p bin
echo "Compiling C++ builtins"
g++ -g -Wall -std=c++17 src/ls.cpp -o bin/ls
g++ -g -Wall -std=c++17 src/pwd.cpp -o bin/pwd
g++ -g -Wall -std=c++17 src/cat.cpp -o bin/cat
g++ -g -Wall -std=c++17 src/echo.cpp -o bin/echo
g++ -g -Wall -std=c++17 src/mkdir.cpp -o bin/mkdir
g++ -g -Wall -std=c++17 src/rmdir.cpp -o bin/rmdir
g++ -g -Wall -std=c++17 src/rm.cpp -o bin/rm
g++ -g -Wall -std=c++17 src/cp.cpp -o bin/cp
g++ -g -Wall -std=c++17 src/mv.cpp -o bin/mv
echo "Done"