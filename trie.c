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
        node->word[MAX_WORD_LENGTH] = NULL; // setting to null may not be needed
        node->children[NUM_CHILDREN] = NULL;
        return node;
};

//void trieNode_insert(struct TrieNode* root, const char* word){
//    printf("trieNode_insert \n");
//    printf("Entered TrieNode_insert with word >> %s \n", *word);
//    printf("Entered TrieNode_insert with word size of >> %d \n", sizeof(word));
//
////    convert the word to a T9 key sequence represented as an array of integers
////    add the word to the trie
//
//    int T9Arr[sizeof(word)];
//    struct Trie* curr = root;
//    for (int i = 0; i < sizeof(word); i++) {
//        printf("char %d >> \n", i);
//        printf("char %d >> %c \n", i, word[i]);
//        printf("in for loop >> %c \n", charToInt(word[i])); // verify this is working
//        T9Arr[i] = charToInt(word[i]);
//    }
//    printf("complete array word >> %c\n", T9Arr); // verify this is working
//    curr->word = T9Arr;
//};


struct TrieNode* trieNode_search(struct TrieNode* root, const int* code, int codelength) {
    //return Null;
};

void trieNode_free(struct TrieNode* root){
    //return Null;
};

void print_trie(struct TrieNode *h) {
  while (h != NULL) {
    printf("%d \n", h->word);
    h = h->children;
  }
}

//char *returnChar(const char word) {
//    return word;
//}

void *returnChar() {
    static char arr[20] = {'g', 'o', 'l', 'd', 'e', 'n'};
    char arr2[20] = "GOLDEN";

    for (int i = 0; i < sizeof(arr); i++) {
        printf("Element %d >> %c \n", i, arr[i]);
        printf("Element %d >> %c \n", i, arr2[i]);
    }
//    return word;
}

int returnNum(int num) {
    return num;
}


main() {
//    printf("%d\n", charToInt('#'));
//
//    struct TrieNode *node = trieNode_new();
//
//    trieNode_insert(node, 'belong');
//    printf("Word >> %c\n", node->word);

//    char myChar1 = 's';
//    char myChar2[40] = "hello world";
//    printf("my char1 >> %c \n", returnChar(myChar1));
//    printf("my char2 >> %c \n", returnChar(myChar2));

//    int myInt;
//    myInt = 5;
//    returnNum(5);
//    printf("my num >> %d \n", returnNum(5));
    returnChar();

}
