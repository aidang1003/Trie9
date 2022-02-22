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
//        const int* buffet;
//        int buffet;

        while(fgets(buffet, BufSize - 1, fq) != NULL) {
            if (buffet == 'exit') {break;}
            int codeLen = strlen(buffet) - 1;

            printf("input string length >> %d\n", codeLen);
            printf("print input string >> %s\n", buffet);

            /*
            Need to turn char input into a const int * that can also fit the '#' character
            this seems impossible with the current architecture of the program
            I will end here
            */

//            struct TrieNode *temp; //create a node temp
//            temp = trieNode_search(root, casBuf, codeLen); // run the search function
//            printNode(temp); // print the node to see if this was done correctly

//            if (temp->word) {
//                printf("here is your word >> %s \n", temp->word); // if the word exists, return it to the user
//            } else {
//                printf("Not found in the current dictionary\n"); // otherwise the word is not in the dictionary
//            }
        }

        fclose(fq);

        return 1;
        printf("program exited \n");

    }
}
