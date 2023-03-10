# Light builtins's Makefile
# A lightweight repository of useful C++/C shell commands
# GitHub: https://www.github.com/awesomelewis2007/light_builtins
# License: GNU General Public License v3.0
#
# Usage:
# make - compiles everything
# make configure_test test_cpp test_c - configures tests and runs tests



CPP_CC = g++
CPP_FLAGS = -g -Wall -std=c++23
CPP_OUTPUT = bin
CPP_SRC = src

C_CC = gcc
C_FLAGS = -g -Wall -std=c2x
C_OUTPUT = bin/c
C_SRC = src/c

all: clean init compile_cpp compile_c

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

compile_c:
	$(C_CC) $(C_FLAGS) $(C_SRC)/ls.c -o $(C_OUTPUT)/ls
	$(C_CC) $(C_FLAGS) $(C_SRC)/pwd.c -o $(C_OUTPUT)/pwd
	$(C_CC) $(C_FLAGS) $(C_SRC)/cat.c -o $(C_OUTPUT)/cat
	$(C_CC) $(C_FLAGS) $(C_SRC)/echo.c -o $(C_OUTPUT)/echo
	$(C_CC) $(C_FLAGS) $(C_SRC)/mkdir.c -o $(C_OUTPUT)/mkdir
	$(C_CC) $(C_FLAGS) $(C_SRC)/rmdir.c -o $(C_OUTPUT)/rmdir
	$(C_CC) $(C_FLAGS) $(C_SRC)/rm.c -o $(C_OUTPUT)/rm
	$(C_CC) $(C_FLAGS) $(C_SRC)/mv.c -o $(C_OUTPUT)/mv

clean:
	rm -rf $(C_OUTPUT)/*
	rm -rf $(CPP_OUTPUT)/*

init:
	mkdir -p $(C_OUTPUT)
	mkdir -p $(CPP_OUTPUT)

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