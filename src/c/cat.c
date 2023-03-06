// Light builtins's (C version)
// cat - concatenate files and print on the standard output
// A lightweight repository of useful C++/C shell commands
// GitHub: https://www.github.com/awesomelewis2007/light_builtins
// License: GNU General Public License v3.0

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
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
            while ((c = getc(fp)) != EOF)
                putchar(c);
            fclose(fp);
        }
    }
    return 0;
}