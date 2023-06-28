/* Light builtins's (C Ultra Light version)
 * rm - remove files or directories
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/lewisevans2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
 */

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "config.h"

int main(int argc, char *argv[]) {
    if (argc >= 2 &&
        (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)) {
        printf("Light Builtins (C Ultra Light) %d.%d.%d-%s\n", VERSION_MAJOR,
               VERSION_MINOR, VERSION_PATCH, EXTRA_VERSION);
        return 0;
    }
    int i;
    for (i = 1; i < argc; i++) {
        if (remove(argv[i]) == -1) {
            perror("Cannot remove file");
            return 1;
        }
    }
    return 0;
}