/* Light builtins's (C version)
 * rmdir - remove empty directories
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
    int i;
    for (i = 1; i < argc; i++) {
        DIR *dir = opendir(argv[i]);
        if (dir) {
            struct dirent *ent;
            while ((ent = readdir(dir)) != NULL) {
                if (strcmp(ent->d_name, ".") != 0 &&
                    strcmp(ent->d_name, "..") != 0) {
                    printf("Directory is not empty\n");
                    return 1;
                }
            }
            closedir(dir);
        } else {
            perror("Cannot open directory");
            return 1;
        }
        if (rmdir(argv[i]) == -1) {
            perror("Cannot remove directory");
            return 1;
        }
    }
    return 0;
}