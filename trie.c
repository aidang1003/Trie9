#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#include "trie.h"

/*

Aidan Gorny
Spring 2022
Trie data structure for implementing T9 auto complete

*/

int charToInt(char input) { // returns the T9 code associated with the character
    //printf("character value >> %d\n", input);
    if (input >= 'a' && input <= 'c') {return 2;}
    if (input >= 'd' && input <= 'f') {return 3;}
    if (input >= 'g' && input <= 'i') {return 4;}
    if (input >= 'j' && input <= 'l') {return 5;}
    if (input >= 'm' && input <= 'o') {return 6;}
    if (input >= 'p' && input <= 's') {return 7;}
    if (input >= 't' && input <= 'v') {return 8;}
    if (input >= 'w' && input <= 'z') {return 9;}
    if (input == '#') {return POUND;}
    return 1;
}

int posNum(const int * num, int pos) { // returns the digit at position pos of an integer
    // return the digit at the position
    // position 0 is the left most digit in the number
    // position n is the right most digit in the number
    int output = (int) num; // cast in order to compile
    int len = floor(log10(abs(output)) + 1;
    for (int i = 0; i < len - pos - 1; i++) {
        output = output / 10;
    }
    return output % 10;
}

struct TrieNode* trieNode_new(){ // initializes a new trie node struct
    int size = sizeof(struct TrieNode);

    struct TrieNode *node = malloc(size);
//    node->word[MAX_WORD_LENGTH] = NULL; //approach 3 implementation
    node->word = NULL;
    node->next = NULL;
    //node->children[NUM_CHILDREN] = malloc(NUM_CHILDREN * size); // make array of tries

    for (int i = 0; i < NUM_CHILDREN; i++) {
        node->children[i] = NULL;
    }
    return node;
};


void trieNode_insert(struct TrieNode * root, const char * word) { // inserts a word at the appropriate position in the trie struct based on the words T9 code
//    printf("Entered trieNode_insert \n");
//    printf("word >> %s \n", word);
//    printNode(root);
    struct TrieNode * current = root;
//    printf("error \n");
    int wordIndex = 0;
//    printf("error2 \n");

    // insert a word into the trie
//    printf("word: %s, word index: %d \n", word, wordIndex);
//    printf("length of word >> %d \n", strlen(word));
    struct TrieNode * child;
    while (strlen(word) - wordIndex) { // change this to a for loop

        char letter = word[wordIndex];
//        printf("line %d\n", 1);

//        printf("with letter for child index >> %c \n", letter);
        int childIndex = charToInt(letter);
//        printf("with num for child index >> %d \n", childIndex);

        child = current->children[childIndex];
//        printf("line %d \n", 2);
        // make new node if there's no child at this index
//        printNode(root);
        if (current->children[childIndex] == NULL) {
//            printf("entered loop \n");
//            printf("child index >> %d \n", childIndex);
            child = trieNode_new();
//            printNode(current);
//            printNode(child);
//            printf("child printed");
            current->children[childIndex] = child;
        }

//        printf("line %d\n", 3);
        current = child;

//        printf("line %d\n", 4);
        wordIndex++;
//
//        printf("line %d\n", 5);
//        printf("in while loop with index = %d and string length of word >> %d\n", wordIndex, strlen(word));
    }

    // if T9 sequence already exists ->'#'
//    printf("After while loop\n");
    if (current->word) { // if current has a word
        while (current && current->children[10]) { // move to the leaf node
            current = current->children[10];
        } // breaks when there is no longer a child in the '#' character
        struct TrieNode * newNode = trieNode_new(); //create a new node
        current->children[10] = newNode; // set the child equal to the new node
    }
    int len = wordIndex + 1;
    current->word = malloc(len);
    strncpy(current->word, word, len); //insert the word into position
}


struct TrieNode* trieNode_search(struct TrieNode* root, const int* code, int codelength) { // find if a word exists for a given T9 code, then returns the node
    int a;
    struct TrieNode* curr = root;
    for (int i = 0; i < codelength; i++) {
        a = posNum(code, i);
//        printf("moved to child %d \n", a);
        if (curr->children[a] == NULL) {
//            printf("entered if stmnt");
            curr->children[a] = trieNode_new();
        }
        curr = curr->children[a];
    }
    return curr;
};

void trieNode_free(struct TrieNode* root){ // frees the lowest initialized node all the way up to the root
    for (int i = 0; i < NUM_CHILDREN; i++) {
        if (root->children[i]) {
            trieNode_free(root->children[i]);
        }
    }
    free(root->word);
    free(root);
};

const char* trieNode_getWord(const struct TrieNode* node) { // returns the word of a given node
    const char *output;
    output = node->word;
    return output;

};

const struct TrieNode* trieNode_getChild(const struct TrieNode* node, int i) { // returns the child of index i at a given node
    const struct TrieNode* child;
    child = node->children[i];
    return child;
};


void printTrie(struct TrieNode * root, int level) { // prints the trie for debugging
  if (root) {
    if (root->word != NULL) {
      printTabs(level);
      struct TrieNode * temp = root;
      printf("word =  ");
      while (temp) {
        printf("%s ->  ", temp->word);
        temp = temp->next;
      }
      printf("NULL\n");
    }
    int i;
    for (i = 0; i < NUM_CHILDREN; i++) {
      struct TrieNode * child = root->children[i];
      if (child != NULL) {
        printTabs(level);
        printf("word >> %s ", child->word); // prints the word of the child
        printf("key=%d, index=%d, level=%d : \n", i + 2, i, level);
        printTrie(child, level + 1);
      }
    }
  }
//  printf("complete \n");
}

void printNode(struct TrieNode * node) { // prints the word in the node and the word of the node's children
    struct TrieNode *curr;
    printf("Node word >> %s \n", node->word);
    printf("With children >> \n");
    for (int i = 2; i < NUM_CHILDREN; i++) {
        curr = node->children[i];
        if (curr) {
            printf("\tChild %d with word >> %s \n", i, curr->word);
        } else {
            printf("\tChild %d has not been initialized \n", i);
        }

    }
}

void printTabs(int numTabs) { // prints tabs numTabs times
  int i;
  for (i = 0; i < numTabs; i++) {
    printf("\t");
  }
}



//void main() { // used for testing, main method in app.c
//    printf("start\n");
//
//    struct TrieNode *node = trieNode_new();
////    printNode(node);
////
////    printf("printing tree >>\n");
////    printTrie(node, 1);
//
//    char *myWord = "abe";
//    char *myWord2 = "abab";
////    printf("Character assigned >>\n");
//
//    trieNode_insert(node, myWord);
//    trieNode_insert(node, myWord2);
////    printNode(node);
////    printf("word inserted >>\n");
//
//    /* Test trieNode_search */
//    struct TrieNode *output;
//    int code = 2222;
//    int codeLength = 4;
//    output = trieNode_search(node, code, codeLength);
//
//////     test trieNode_getWord
////    printf("manual word >> %s\n", trieNode_getWord(output));
//
//    printNode(output);
//
//    printTrie(node, 1);
////    printNode(node);
//
//
//    printf("Done. \n");
//
//}
