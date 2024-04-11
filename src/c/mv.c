/* Light builtins's (C version)
 * mv - move (rename) files
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/0x4248/light_builtins
 * Licence: GNU General Public License v3.0
 * By: 0x4248
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
        printf("Light Builtins (C) %d.%d.%d-%s\n", VERSION_MAJOR, VERSION_MINOR,
               VERSION_PATCH, EXTRA_VERSION);
        return 0;
    }
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
