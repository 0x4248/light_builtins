/* Light builtins's (C version)
 * pwd - print name of current/working directory
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/0x4248/light_builtins
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "config.h"

int main(int argc, char *argv[]) {
    if (argc >= 2 &&
        (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)) {
        printf("Light Builtins (C) %d.%d.%d-%s\n", VERSION_MAJOR, VERSION_MINOR,
               VERSION_PATCH, EXTRA_VERSION);
        return 0;
    }
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        fprintf(stdout, "%s", cwd);
        printf("\n");
    } else {
        perror("getcwd() error");
        return 1;
    }
    return 0;
}
