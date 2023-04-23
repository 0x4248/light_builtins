/* Light builtins's (C Ultra Light version)
 * date - display the current date and time
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/awesomelewis2007/light_builtins
 * Licence: GNU General Public License v3.0
 * By: Lewis Evans
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "config.h"

int main(int argc, char *argv[]) {
    if (argc >= 2 && (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)) {
        printf("Light Builtins (C Ultra Light) %d.%d.%d-%s\n", VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH, EXTRA_VERSION);
        return 0;
    }

    time_t now;
    time(&now);

    char date[100];
    strftime(date, sizeof(date), "%a %b %d %H:%M:%S %Z %Y", localtime(&now));
    printf("%s\n", date);

    return 0;
}
