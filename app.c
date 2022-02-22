#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "trie.h"
#include "trie.c"

#define BUFSIZ 1000

/*

Aidan Gorny
Spring 2022
App that takes in a file of dictionary words to build the trie data structure

*/


int main(int argc, char *argv[]) {
//    if (argc) {
    if (argc != 3) {
        printf("Number of arguments >> %d \n", argc);
        printf("incorrect amount of arguments\n");
        return 0;
    } else {

        struct TrieNode *root = trieNode_new();
        int BufSize = BUFSIZ;

        FILE *fp = fopen(argv[1], "r"); /* "r" = open for reading */
        char buffer[BufSize]; /* a buffer to hold what you read in */

        /* read in one line, up to BufSize-1 in length */
        while(fgets(buffer, BufSize - 1, fp) != NULL) {
//            printf ("word string >> %s\n", buffer);
            trieNode_insert(root, buffer);
        }
        fclose(fp);  /* close the file */

//        printTrie(root, 1);


        BufSize = BUFSIZ;
        /* open other input file now */
        FILE *fq = fopen(argv[2], "r");

        char buffet[BufSize]; /* a buffer to hold what you read in */

        while(fgets(buffet, BufSize - 1, fq) != NULL) {
            if (buffet == 'exit') {break;}
            int codeLen = strlen(buffet) - 1;

            printf("input string length >> %d\n", codeLen);
            printf("print buffet type string >> %s\n", buffet);

            const int* casBuf = (const int*) buffet;
            printf("print casBuf type const int*>> %ls\n", casBuf);

//            struct TrieNode *temp;
//            temp = trieNode_search(root, casBuf, codeLen);
//            printNode(temp);
        }
        fclose(fq);

        return 1;
        printf("program exited \n");

    }
}
