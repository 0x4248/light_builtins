/* Light builtins's (C version)
 * rmdir - remove empty directories
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

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
        DIR *dir = opendir(argv[i]);
        if (dir) {
            struct dirent *ent;
            while ((ent = readdir(dir)) != NULL) {
                if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
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