/* Light builtins's (C version)
 * mkdir - make directories
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
 * By: Lewis Evans
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

int main(int argc, char *argv[]) {
    if (argc >= 2 && (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)) {
        printf("Light Builtins (C) %d.%d.%d-%s\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, EXTRA_VERSION);
        return 0;
    }
    int i;
    for (i = 1; i < argc; i++) {
        if (mkdir(argv[i], 0777) == -1) {
            perror("Cannot create directory");
            return 1;
        }
    }
    return 0;
}
