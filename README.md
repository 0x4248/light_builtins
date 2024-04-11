# 📦 Light Builtin's
[![CodeFactor](https://www.codefactor.io/repository/github/0x4248/light_builtins/badge/master)](https://www.codefactor.io/repository/github/0x4248/light_builtins/overview/master)
![GitHub repo size](https://img.shields.io/github/repo-size/0x4248/light_builtins)

This is a repository of the linux builtin commands that is lightweight and fast.

The commands are written in C++, C, Rust and Python. There is also a lighter weight version which has smaller code size and less features. Is also written in C.

## 📝 Commands List
Here is a list of the commands:
- `ls` - List directory contents.
- `pwd` - Print name of current/working directory.
- `cat` - Concatenate files and print on the standard output.
- `echo` - Display a line of text.
- `mkdir` - Create a directory.
- `rmdir` - Remove a directory.
- `rm` - Remove files or directories.
- `cp` - Copy files and directories.
- `mv` - Move (rename) files.
- `touch` - Change file timestamps.
- `date` - Display the current time and date.
- `help` - Display help information.
- `exit` - Exit the shell.

For documentation on the commands, see the [doc/README.md](doc/README.md) folder.

## ✅ Availability

Here are the commands and their availability:

| Command | C++ |    C    | Ultra light | Rust | Python |
|---------|-----|---------|-------------|------|--------|
| ls      | Yes | Yes     | Yes         | Yes  | Yes    |
| pwd     | Yes | Yes     | Yes         | Yes  | Yes    |
| cat     | Yes | Yes     | Yes         | Yes  | Yes    |
| echo    | Yes | Yes     | Yes         | Yes  | Yes    |
| mkdir   | Yes | Yes     | Yes         | Yes  | Yes    |
| rmdir   | Yes | Yes     | Yes         | Yes  | Yes    |
| rm      | Yes | Yes     | Yes         | Yes  | Yes    |
| cp      | Yes | **No**  | Yes         | Yes  | Yes    |
| mv      | Yes | Yes     | Yes         | Yes  | Yes    |
| touch   | Yes | Yes     | Yes         | Yes  | Yes    |
| date    | Yes | Yes     | Yes         | Yes  | Yes    |

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

### Build using sh
If you want to build using sh instead of make, run the following command:
```bash
sh tools/build_c.sh
sh tools/build_cpp.sh
```
The binaries will be in the `bin` folder. C versions of the commands will be in the `bin/c` folder.

To clean the build, run the following command:
```bash
sh tools/clean.sh
```

### Build using cmake
If you want to build using cmake instead of make, run the following command:
```bash
sh tools/cmake.sh
```

> [!WARNING]
> This will only build the C++ versions of the commands and will also output to the `build` folder.

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

## 📝 Licence

This project is licenced under the GNU General Public Licence v3.0 - see the [LICENCE.md](LICENCE.md) file for details.