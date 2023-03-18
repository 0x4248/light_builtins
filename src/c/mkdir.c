/* Light builtins's (C version)
 * mkdir - make directories
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i;
    for (i = 1; i < argc; i++) {
        if (mkdir(argv[i], 0777) == -1) {
            perror("Cannot create directory");
            return 1;
        }
    }
    return 0;
}
