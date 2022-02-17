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

struct TrieNode* trieNode_new(){
        struct TrieNode *node = malloc(1 * sizeof(struct TrieNode));
        node->word[MAX_WORD_LENGTH];
        node->children[NUM_CHILDREN]; //make array 2-10 of pointers
        return node;
};

void trieNode_insert(struct TrieNode* root, const char* word){
//    convert the word to a T9 key sequence represented as an array of integers
//    add the word to the trie
//    create array of 2-10

    printf("Entered TrieNode_insert with word >> %s \n", word); // testing
    printf("Entered TrieNode_insert with size >> %d \n", strlen(word)); // testing


    struct Trie* curr = root;

    int T9Arr[sizeof(word)];

    for (int i = 0; i < strlen(word); i++) {
        T9Arr[i] = charToInt(word[i]);
        if (curr->children[T9Arr[i] == NULL) {
            curr->children[T9Arr[i]] = trieNode_new();
        }
        curr = curr->children[T9Arr[i]];
    }


};


struct TrieNode* trieNode_search(struct TrieNode* root, const int* code, int codelength) {
    //return Null;
};

void trieNode_free(struct TrieNode* root){
    //return Null;
};

const char* trieNode_getWord(const struct TrieNode* node);

const struct TrieNode* trieNode_getChild(const struct TrieNode* node, int i);


void print_trie(struct TrieNode *h) {
  while (h != NULL) {
    printf("%d \n", h->word);
    h = h->children;
  }
}



main() {
    struct TrieNode *node = trieNode_new();
    char *arr = "golden";
    trieNode_insert(node, arr);

}
