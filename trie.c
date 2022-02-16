#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "trie.h"


int charToInt(char input) {
    if (input >= 'a' && input <= 'c') {return 2;}
    if (input >= 'd' && input <= 'f') {return 3;}
    if (input >= 'g' && input <= 'i') {return 4;}
    if (input >= 'j' && input <= 'l') {return 5;}
    if (input >= 'm' && input <= 'o') {return 6;}
    if (input >= 'p' && input <= 's') {return 7;}
    if (input >= 't' && input <= 'v') {return 8;}
    if (input >= 'w' && input <= 'z') {return 9;}

}

void trieNode_insert(struct TrieNode* root, const char* word){
    struct Trie* curr = root;
    while(*word) {

    }
};

struct TrieNode* trieNode_search(struct TrieNode* root, const int* code, int codelength) {
    //return Null;
};

void trieNode_free(struct TrieNode* root){
    //return Null;
};

void foo() {
}

main() {
    printf("%d\n", charToInt('d'));
    printf("%d \n", 'a');
    printf("%d \n", 'c');
}
