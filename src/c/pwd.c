/* Light builtins's (C version)
 * pwd - print name of current/working directory
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * License: GNU General Public License v3.0
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
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
