// Light builtins's (C version)
// mv - move (rename) files
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
    if (argc < 3) {
        printf("Usage: mv <source> <destination>\n");
        return 1;
    }
    if (rename(argv[1], argv[2]) == -1) {
        perror("Cannot move file");
        return 1;
    }
    return 0;
}
