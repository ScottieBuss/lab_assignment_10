#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Trie {
    struct Trie children[26];
    int count;
};

void insert(struct Trie **ppTrie, charword) {
    if (*ppTrie == NULL) {
        ppTrie = malloc(sizeof(struct Trie));
        memset((ppTrie)->children, 0, sizeof((ppTrie)->children));
        (ppTrie)->count = 0;
    }
    struct Trie pTrie =ppTrie;
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (pTrie->children[index] == NULL) {
            pTrie->children[index] = malloc(sizeof(struct Trie));
            memset(pTrie->children[index]->children, 0, sizeof(pTrie->children[index]->children));
            pTrie->children[index]->count = 0;
        }
        pTrie = pTrie->children[index];
    }
    pTrie->count++;
}

int numberOfOccurances(struct Trie pTrie, charword) {
    for (int i = 0; i < strlen(word); i++) {
        int index = word[i] - 'a';
        if (pTrie->children[index] == NULL) {
            return 0;
        }
        pTrie = pTrie->children[index];
    }
    return pTrie->count;
}

struct Trie deallocateTrie(struct TriepTrie) {
    if (pTrie != NULL) {
        for (int i = 0; i < 26; i++) {
            if (pTrie->children[i] != NULL) {
                deallocateTrie(pTrie->children[i]);
            }
        }
        free(pTrie);
    }
    return NULL;
}

int main(void) {
    int n;
    scanf("%d", &n);

    struct Trie trie = NULL;
    char word[101];
    for (int i = 0; i < n; i++) {
        scanf("%s", word);
        insert(&trie, word);
    }

    charpWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for (int i = 0; i < 5; i++) {
        printf("\t%s : %d\n", pWords[i], numberOfOccurances(trie, pWords[i]));
    }
    return 0;
}
