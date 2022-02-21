#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "trie.h"

int main(int argc, char *argv[]) {
    int bufferSize = 1000;

    FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */

    char buff[bufferSize]; /* a buffer to hold what you read in */

    /* read in one line, up to bufferSize-1 in length */
    while(fgets(buff, bufferSize - 1, fp) != NULL)
    {
        /* buff has one line of the file, do with it what you will... */

        printf ("string >> %s\n", buff); /* ...such as show it on the screen */
    }
    fclose(fp);  /* close the file */

    return 1;
}
