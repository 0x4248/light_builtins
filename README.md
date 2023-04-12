# 📦 Light Builtin's
[![CodeFactor](https://www.codefactor.io/repository/github/awesomelewis2007/light_builtins/badge/master)](https://www.codefactor.io/repository/github/awesomelewis2007/light_builtins/overview/master)
![GitHub repo size](https://img.shields.io/github/repo-size/awesomelewis2007/light_builtins)

This is a repository of the linux builtin commands that is lightweight and fast.

The commands are written in C++, C and Rust.

## 📝 Commands List
- `ls` - List directory contents `C++` `C` `Ultra light` `Rust`
- `pwd` - Print name of current/working directory `C++` `C` `Ultra light` `Rust`
- `cat` - Concatenate files and print on the standard output`C++` `C` `Ultra light` `Rust`
- `echo` - Display a line of text `C++` `C` `Ultra light` `Rust`
- `mkdir` - Create a directory`C++` `C` `Ultra light` `Rust`
- `rmdir` - Remove a directory `C++` `C` `Ultra light` `Rust`
- `rm` - Remove files or directories`C++` `C` `Ultra light` `Rust`
- `cp` - Copy files and directories `C++` `Ultra light` `Rust`
- `mv` - Move (rename) files `C++` `C` `Ultra light` `Rust`
- `touch` - Change file timestamps `C++` `C`
- `date` - Display the current time and date `C++` `C`

For documentation on the commands, see the [doc/README.md](doc/README.md) folder.

## 📦 Dependencies
- `make`
- `gcc`
- `g++`
- `rustc`

## 🔨 Build

To build the project run the following command:

```bash
make
```
The binaries will be in the `bin` folder. C versions of the commands will be in the `bin/c` folder.

If you want to build the C versions of the commands, run the following command:
```bash
make compile_c
```
The binaries will be in the `bin/c` folder.

If you want to build the Rust versions of the commands, run the following command:
```bash
make compile_rust
```

The binaries will be in the `bin/rust` folder.

If you want to build the ultra light versions of the commands, run the following command:
```bash
make ultra_light
```

The binaries will be in the `bin` folder.

To clean the build, run the following command:
```bash
make clean
```

## 🔨 Alternative build
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

## 🏃‍♂️ Ultra light

The ultra light version of the light builtins is in the `src/ultra_light` folder. This version has minimal code and low compile size.

To build the ultra light version, run the following command:
```bash
make ultra_light
```
The binaries will be in the `bin/` folder.

## ⚙️ Rust
The rust version of the commands are in the `src/rust` folder.

To build the rust version, run the following command:
```bash
make compile_rust
```

The binaries will be in the `bin/rust` folder.
