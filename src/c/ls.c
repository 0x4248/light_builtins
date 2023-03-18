/* Light builtins's (C version)
 * ls - list directory contents
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
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
