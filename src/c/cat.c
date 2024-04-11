/* Light builtins's (C version)
 * cat - concatenate files and print on the standard output
 * A lightweight repository of useful shell commands
 * GitHub: https://www.github.com/0x4248/light_builtins
 * Licence: GNU General Public License v3.0
 * By: 0x4248
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

int main(int argc, char *argv[]) {
    if (argc >= 2 &&
        (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)) {
        printf("Light Builtins (C) %d.%d.%d-%s\n", VERSION_MAJOR, VERSION_MINOR,
               VERSION_PATCH, EXTRA_VERSION);
        return 0;
    }
    FILE *fp;
    int c;

    if (argc == 1) {
        printf("cat: usage: cat [file ...]\n");
        exit(1);
    }
    while (--argc > 0) {
        if ((fp = fopen(*++argv, "r")) == NULL) {
            printf("cat: can't open %s\n", *argv);
            exit(1);
        } else {
            while ((c = getc(fp)) != EOF) {
                putchar(c);
            }
            fclose(fp);
        }
    }
    return 0;
}