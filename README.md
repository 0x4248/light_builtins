# Light Builtin's
This is a repository of the linux builtin commands that is lightweight and fast.

You can use these command in your shell or in your program. There are also C versions of the commands.

## Commands List
- `ls` - List directory contents ![C++_logo](https://img.shields.io/badge/cpp-magenta) 
- `pwd` - Print name of current/working directory ![C++_logo](https://img.shields.io/badge/cpp-magenta) ![C_logo](https://img.shields.io/badge/c-gray)
- `cat` - Concatenate files and print on the standard output ![C++_logo](https://img.shields.io/badge/cpp-magenta) 
- `echo` - Display a line of text ![C++_logo](https://img.shields.io/badge/cpp-magenta) ![C_logo](https://img.shields.io/badge/c-gray)
- `mkdir` - Create a directory ![C++_logo](https://img.shields.io/badge/cpp-magenta) ![C_logo](https://img.shields.io/badge/c-gray)
- `rmdir` - Remove a directory ![C++_logo](https://img.shields.io/badge/cpp-magenta) ![C_logo](https://img.shields.io/badge/c-gray)
- `rm` - Remove files or directories ![C++_logo](https://img.shields.io/badge/cpp-magenta) 
- `cp` - Copy files and directories ![C++_logo](https://img.shields.io/badge/cpp-magenta) 
- `mv` - Move (rename) files ![C++_logo](https://img.shields.io/badge/cpp-magenta) 

## Build
To build the project, you need to have `gcc` and `make` installed.

Then, run the following command:
```bash
make
```
The binaries will be in the `bin` folder. C versions of the commands will be in the `bin/c` folder.

If you want to build the C versions of the commands, run the following command:
```bash
make compile_c
```
The binaries will be in the `bin/c` folder.

To clean the build, run the following command:
```bash
make clean
```

## Alternative build
If you want to build using sh instead of make, run the following command:
```bash
sh scripts/build_c.sh
sh scripts/build_cpp.sh
```
The binaries will be in the `bin` folder. C versions of the commands will be in the `bin/c` folder.

To clean the build, run the following command:
```bash
sh scripts/clean.sh
```

