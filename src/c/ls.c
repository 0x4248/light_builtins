/* Light builtins's (C version)
 * ls - list directory contents
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

#include "config.h"

int main(int argc, char *argv[]) {
    if (argc >= 2 &&
        (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)) {
        printf("Light Builtins (C) %d.%d.%d-%s\n", VERSION_MAJOR, VERSION_MINOR,
               VERSION_PATCH, EXTRA_VERSION);
        return 0;
    }
    DIR *dir;
    struct dirent *ent;
    char *path = argv[1];
    if (argc == 1) {
        path = ".";
    }
    if ((dir = opendir(path)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_name[0] != '.') {
                struct stat st;
                char *fullpath = malloc(strlen(path) + strlen(ent->d_name) + 2);
                strcpy(fullpath, path);
                strcat(fullpath, "/");
                strcat(fullpath, ent->d_name);
                stat(fullpath, &st);
                if (S_ISDIR(st.st_mode)) {
                    printf("/%s ", ent->d_name);
                } else {
                    printf("%s ", ent->d_name);
                }
            }
        }
        printf("\n");
        closedir(dir);
    } else {
        printf("ls: cannot access '%s': No such file or directory\n", path);
    }
    return 0;
}
