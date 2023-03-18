# Light builtins's Makefile
# A lightweight repository of useful C++/C shell commands
# GitHub: https://www.github.com/awesomelewis2007/light_builtins
# License: GNU General Public License v3.0
#
# Usage:
# make - compiles everything
# make configure_test test_cpp test_c - configures tests and runs tests



CPP_CC = g++
CPP_FLAGS = -g -Wall -std=c++23 -Os
CPP_OUTPUT = bin
CPP_SRC = src

C_CC = gcc
C_FLAGS = -g -Wall -std=c2x -Os
C_OUTPUT = bin/c
C_SRC = src/c

RUST_CC = rustc
RUST_FLAGS = 
RUST_OUTPUT = bin/rust
RUST_SRC = src/rust

all: clean init compile_cpp compile_c compile_rust

help:
	@echo "Light builtins's Makefile"
	@echo "A lightweight repository of useful C++/C shell commands"
	@echo "GitHub: https://www.github.com/awesomelewis2007/light_builtins"
	@echo "License: GNU General Public License v3.0"
	@echo ""
	@echo "Usage:"
	@echo "command                  | description"
	@echo "-------------------------|--------------------------------"
	@echo "make                     | compiles everything"
	@echo "make init                | initializes the bin directory"
	@echo "make compile_cpp         | compiles C++ builtins"
	@echo "make compile_ultra_light | compiles C++ builtins with ultra light mode"
	@echo "make compile_c           | compiles C builtins"
	@echo "make compile_rust        | compiles Rust builtins"
	@echo "make clean               | cleans the bin directory"
	@echo "make configure_test      | configures tests"
	@echo "make test_cpp            | runs C++ builtins tests"
	@echo "make test_c              | runs C builtins tests"

compile_cpp:
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/ls.cpp -o $(CPP_OUTPUT)/ls
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/pwd.cpp -o $(CPP_OUTPUT)/pwd
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/cat.cpp -o $(CPP_OUTPUT)/cat
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/echo.cpp -o $(CPP_OUTPUT)/echo
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/mkdir.cpp -o $(CPP_OUTPUT)/mkdir
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/rmdir.cpp -o $(CPP_OUTPUT)/rmdir
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/rm.cpp -o $(CPP_OUTPUT)/rm
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/cp.cpp -o $(CPP_OUTPUT)/cp
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/mv.cpp -o $(CPP_OUTPUT)/mv

compile_ultra_light:
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/ultra_light/ls.cpp -o $(CPP_OUTPUT)/ls
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/ultra_light/pwd.cpp -o $(CPP_OUTPUT)/pwd
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/ultra_light/cat.cpp -o $(CPP_OUTPUT)/cat
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/ultra_light/echo.cpp -o $(CPP_OUTPUT)/echo
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/ultra_light/mkdir.cpp -o $(CPP_OUTPUT)/mkdir
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/ultra_light/rmdir.cpp -o $(CPP_OUTPUT)/rmdir
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/ultra_light/rm.cpp -o $(CPP_OUTPUT)/rm
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/ultra_light/cp.cpp -o $(CPP_OUTPUT)/cp
	$(CPP_CC) $(CPP_FLAGS) $(CPP_SRC)/ultra_light/mv.cpp -o $(CPP_OUTPUT)/mv

compile_c:
	$(C_CC) $(C_FLAGS) $(C_SRC)/ls.c -o $(C_OUTPUT)/ls
	$(C_CC) $(C_FLAGS) $(C_SRC)/pwd.c -o $(C_OUTPUT)/pwd
	$(C_CC) $(C_FLAGS) $(C_SRC)/cat.c -o $(C_OUTPUT)/cat
	$(C_CC) $(C_FLAGS) $(C_SRC)/echo.c -o $(C_OUTPUT)/echo
	$(C_CC) $(C_FLAGS) $(C_SRC)/mkdir.c -o $(C_OUTPUT)/mkdir
	$(C_CC) $(C_FLAGS) $(C_SRC)/rmdir.c -o $(C_OUTPUT)/rmdir
	$(C_CC) $(C_FLAGS) $(C_SRC)/rm.c -o $(C_OUTPUT)/rm
	$(C_CC) $(C_FLAGS) $(C_SRC)/mv.c -o $(C_OUTPUT)/mv

compile_rust:
	$(RUST_CC) $(RUST_FLAGS) $(RUST_SRC)/ls.rs -o $(RUST_OUTPUT)/ls
	$(RUST_CC) $(RUST_FLAGS) $(RUST_SRC)/pwd.rs -o $(RUST_OUTPUT)/pwd
	$(RUST_CC) $(RUST_FLAGS) $(RUST_SRC)/cat.rs -o $(RUST_OUTPUT)/cat
	$(RUST_CC) $(RUST_FLAGS) $(RUST_SRC)/echo.rs -o $(RUST_OUTPUT)/echo
	$(RUST_CC) $(RUST_FLAGS) $(RUST_SRC)/mkdir.rs -o $(RUST_OUTPUT)/mkdir
	$(RUST_CC) $(RUST_FLAGS) $(RUST_SRC)/rmdir.rs -o $(RUST_OUTPUT)/rmdir
	$(RUST_CC) $(RUST_FLAGS) $(RUST_SRC)/rm.rs -o $(RUST_OUTPUT)/rm

clean:
	rm -rf $(C_OUTPUT)/*
	rm -rf $(CPP_OUTPUT)/*
	rm -rf $(RUST_OUTPUT)/*

init:
	mkdir -p $(C_OUTPUT)
	mkdir -p $(CPP_OUTPUT)
	mkdir -p $(RUST_OUTPUT)

configure_test:
	mkdir test
	echo "This is a test file" > test/test.txt
	echo "This is a test file" > test/test2.txt
	echo "This is a test file" > test/test3.txt
	echo "This is a test file" > test/test4.txt
	mkdir test/test_dir
	mkdir test/test_dir2


test_cpp:
	$(CPP_OUTPUT)/ls test
	$(CPP_OUTPUT)/pwd
	$(CPP_OUTPUT)/cat test/test.txt
	$(CPP_OUTPUT)/echo "This is a test"
	$(CPP_OUTPUT)/mkdir test/test_dir3
	$(CPP_OUTPUT)/rmdir test/test_dir3
	$(CPP_OUTPUT)/rm test/test.txt
	$(CPP_OUTPUT)/cp test/test2.txt test/test_copy.txt
	$(CPP_OUTPUT)/mv test/test3.txt test/test_mv.txt

test_c:
	$(C_OUTPUT)/pwd
	$(C_OUTPUT)/echo "This is a test"
	$(C_OUTPUT)/mkdir test
	$(C_OUTPUT)/rmdir test
