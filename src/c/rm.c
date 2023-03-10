// Light builtins's (C version)
// rm - remove files or directories
// A lightweight repository of useful C++/C shell commands
// GitHub: https://www.github.com/awesomelewis2007/light_builtins
// License: GNU General Public License v3.0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;
    for (i = 1; i < argc; i++) {
        if (remove(argv[i]) == -1) {
            perror("Cannot remove file");
            return 1;
        }
    }
    return 0;
}