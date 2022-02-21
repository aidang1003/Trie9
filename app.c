#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "trie.h"

int main(int argc, char *argv[]) {
    printf("%d\n", argc);
    int len = argc;
    for (int i = 0; i < len; i++) {
        printf("string %d >> %s\n", i, argv[i]);
    }
    return 1;
}
