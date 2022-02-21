#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "trie.h"
#include "trie.c"

int main(int argc, char *argv[]) {
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

//    printTrie(root);

    return 1;
}
