#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "trie.h"
#include "trie.c"

#define BUFSIZ 1000

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

        struct TrieNode *root = trieNode_new();
        FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */
        char buff[BUFSIZ]; /* a buffer to hold what you read in */

        /* read in one line, up to BUFSIZ-1 in length */
        while(fgets(buff, BUFSIZ - 1, fp) != NULL)
        {
            printf ("word string >> %s\n", buff);
//            trieNode_insert(root, buff);
        }
        fclose(fp);  /* close the file */


        /* open other input file now */
        FILE *fq = fopen(argv[2], "r");

//        char buff[BUFSIZ]; /* a buffer to hold what you read in */
        while(fgets(buff, BUFSIZ - 1, fq) != NULL)
        {
            printf ("input string >> %s\n", buff);
        }
        fclose(fq);

        return 1;

    }

}
