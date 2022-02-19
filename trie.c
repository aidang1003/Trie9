#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>

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

int posNum(const int * num, int pos) {
    // return the digit at the position
    // position 0 is the left most digit in the number
    // position n is the right most digit in the number
    int output = num;
    int len = floor(log10(abs(num))) + 1;
    for (int i = 0; i < len - pos - 1; i++) {
        output = output / 10;
    }
    return output % 10;
}

struct TrieNode* trieNode_new(){
        int size = sizeof(struct TrieNode);

        struct TrieNode *node = malloc(size);
        node->word[MAX_WORD_LENGTH] = NULL;
        node->next = NULL;
        node->children[NUM_CHILDREN]; // make array of tries

        for (int i = 2; i < NUM_CHILDREN; i++) {
            node->children[i] = malloc(size);
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
        struct TrieNode * child = curr->children[T9];
        if (!child) { // if the child at index of the T9 conversion is empty
            child = trieNode_new;
            curr->children[T9] = child; // create a new Trie Node
        }
        curr = curr->children[T9]; // set current to child of index T9 number
        // curr = trieNode_new(); // create a new node
    }

    while (!curr->word) { // handles # case
        curr = curr->children[10]; // sets the current to index of 10
    }
    for (int i = 0; i < strlen(word); i++) {
        curr->word[i] = word[i]; // assigns the word to the trie node
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
    // free for the entire struct
    free(root->word);
    for (int i = 0; i < NUM_CHILDREN; i++) {
        trieNode_free(root->children[i]);
        // how will this loop end?
    }
    free(root->children);
    free(root);
};

const char* trieNode_getWord(const struct TrieNode* node) { return NULL; };

const struct TrieNode* trieNode_getChild(const struct TrieNode* node, int i) { return NULL; };


void printTrie(struct TrieNode * root, int level) { // prints the trie for debugging
  if (root) {
    if (root->word != NULL) {
      printTabs(level);
      struct TrieNode * temp = root;
      printf("word = ");
      while (temp) {
        printf("%s -> ", temp->word);
        temp = temp->next;
      }
      printf("NULL\n");
    }
    int i;
    for (i = 0; i < NUM_CHILDREN; i++) {
      struct TrieNode * child = root->children[i];
      if (child != NULL) {
        printTabs(level);
        printf("key=%d, index=%d, level=%d : \n", i + 2, i, level);
        printTrie(child, level + 1);
      }
    }
  }
}

void printTabs(int numTabs) {
  int i;
  for (i = 0; i < numTabs; i++) {
    printf("\t");
  }
}



main() {
    printf("start\n");
    struct TrieNode *node = trieNode_new();

    printf("printing tree >>\n");
    printTrie(node, 1);

//    printf("tree printed >>\n");
//    char myWord = "good";
//
//    trieNode_insert(node, myWord);
//    printTrie(node, 1);


//    const int a = 8765;
//    for (int i = 0; i < 4; i++) {
//        printf("the %d digit is %d \n", i + 1, posNum(a, i));
//    }

}
