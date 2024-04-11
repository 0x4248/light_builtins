/* Light builtins's (C Version)
 * touch - create a new file or update the timestamp of an existing file
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/0x4248/light_builtins
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 */

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc >= 2 &&
        (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)) {
        printf("Light Builtins (C) %d.%d.%d-%s\n", VERSION_MAJOR, VERSION_MINOR,
               VERSION_PATCH, EXTRA_VERSION);
        return 0;
    }

    if (argc != 2) {
        fprintf(stderr, "Usage: touch [Filename]\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "w");
    if (fp == NULL) {
        fprintf(stderr, "Touch: error creating file\n");
        return 1;
    }

    time_t now;
    time(&now);

    fprintf(fp, " ");

    fseek(fp, -1, SEEK_CUR);
    fputc(fgetc(fp), fp);

    struct tm *timeinfo;
    timeinfo = localtime(&now);
    char time_str[80];
    strftime(time_str, 80, "%c", timeinfo);

    fclose(fp);

    return 0;
}
