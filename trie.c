#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "trie.h"

int charToInt(char input) {
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


}

int posNum(int num, int pos) {
    // return the digit at the position
    // position 0 is the left most digit in the number
    // position n is the right most digit in the number
    int output;
    int len = floor(log10(abs(num))) + 1;
    for (int i = 0; i < len - pos - 1; i++) {
        num = num / 10;
    }
    return num % 10;
}

struct TrieNode* trieNode_new(){
        struct TrieNode *node = malloc(1 * sizeof(struct TrieNode));
        node->word[MAX_WORD_LENGTH];
        node->children[NUM_CHILDREN]; // make array of tries

        int i = 0;
        while (i < NUM_CHILDREN) {
            node->children[i] = NULL;
        }
        return node;
};

void trieNode_insert(struct TrieNode* root, const char* word){
//    convert the word to a T9 key sequence represented as an array of integers
//    add the word to the trie

    struct TrieNode* curr = root; // create a pointer to the root trie
    // This used to be called Trie* curr and caused a lot of problems

    for (int i = 0; i < strlen(word); i++) {
        int T9 = charToInt(word[i]); // set integer T9 equal to the char in the word
        if (curr->children[T9] == NULL) { // if the child at index of the T9 conversion is empty
            curr->children[T9] = trieNode_new(); // create a new Trie Node
        }
        curr = curr->children[T9]; // set current to child of index T9 number
        // curr = trieNode_new(); // create a new node
    }

    while (curr->word != NULL) { // handles # case
        curr = curr->children[10]; // sets the current to index of 10
    }

    if (curr->word == NULL) { // probable not needed as the while loop takes care of finding the NULL word
        for (int i = 0; i < strlen(word); i++) {
            curr->word[i] = word[i]; // assigns the word to the trie node
        }
    }
};


struct TrieNode* trieNode_search(struct TrieNode* root, const int* code, int codelength) {
    int a;
    struct TrieNode* curr = root;
    for (int i = 0; i < codelength; i++) {
        a = posNum(code, i);
        printf("moved to child %d \n", a);
        if (curr->children[a] == NULL) {
            printf("entered if stmnt");
            curr->children[a] = trieNode_new();
        }
        curr = curr->children[a];
    }
    return curr;
};

void trieNode_free(struct TrieNode* root){
    //return Null;
};

const char* trieNode_getWord(const struct TrieNode* node) { return NULL; };

const struct TrieNode* trieNode_getChild(const struct TrieNode* node, int i) { return NULL; };


void printTrie(struct TrieNode *h) {
    printf("Word: %s \n", h->word);
    for (int i =0; i < NUM_CHILDREN; i++) {
        printf("Children word %d >> %s", i, h->children[i]->word); // not sure how to print an array of trie structures
    }
}



main() {
    struct TrieNode *node = trieNode_new();
    printTrie(node);
//    char *arr = "golden";
//    trieNode_insert(node, arr);

    const int* myInt = 78945;
    trieNode_search(node, myInt, 5);


}
