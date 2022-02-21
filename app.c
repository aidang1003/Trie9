#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "trie.h"
#include "trie.c"

/*

Aidan Gorny
Spring 2022
App that takes in a file of dictionary words to build the trie data structure

*/

int main(int argc, char *argv[]) {
    if (argc) {
//    if (argc != 3) {
        printf("incorrect amount of arguments\n");
        return 0;
    } else {
        printf("Number of arguments >> %d", argc);

        int bufferSize = 1000;
        struct TrieNode *root = trieNode_new();

        FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */

        char buff[bufferSize]; /* a buffer to hold what you read in */

        /* read in one line, up to bufferSize-1 in length */
        while(fgets(buff, bufferSize - 1, fp) != NULL)
        {
            /* buff has one line of the file, do with it what you will... */

            printf ("string >> %s\n", buff); /* ...such as show it on the screen */

            trieNode_insert(root, buff);
        }
        fclose(fp);  /* close the file */

        return 1;

    }

}
