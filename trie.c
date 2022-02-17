#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "trie.h"

struct TrieNode* trieNode_new(char data){
        struct TrieNode *node = malloc(1 * sizeof(struct TrieNode));
        node->word = data;
        node->children = NULL;
        return node;
};


int charToInt(char input) {
    if (input >= 'a' && input <= 'c') {return 2;}
    if (input >= 'd' && input <= 'f') {return 3;}
    if (input >= 'g' && input <= 'i') {return 4;}
    if (input >= 'j' && input <= 'l') {return 5;}
    if (input >= 'm' && input <= 'o') {return 6;}
    if (input >= 'p' && input <= 's') {return 7;}
    if (input >= 't' && input <= 'v') {return 8;}
    if (input >= 'w' && input <= 'z') {return 9;}
    if (input == '#') {return 10;}

}

void trieNode_insert(struct TrieNode* root, const char* word){
    //convert the word to a T9 key sequence represented as an array of integers
    //add the word to the trie
    int T9Arr[sizeof(word)];
    struct Trie* curr = root;
    for (int i = 0; i < sizeof(word); i++) {
        printf("%d\n", charToInt(word[i])); // verify this is working
        t9Arr[i] = charToInt(word[i]);
    }
};

struct TrieNode* trieNode_search(struct TrieNode* root, const int* code, int codelength) {
    //return Null;
};

void trieNode_free(struct TrieNode* root){
    //return Null;
};

main() {
    printf("%d\n", charToInt('d'));
    printf("%d\n", charToInt('q'));
    printf("%d\n", charToInt('#'));
}
