#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFrequency;

void addWord(WordFrequency words[], int *size, char *word) {
    for (int i = 0; i < *size; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[*size].word, word);
    words[*size].count = 1;
    (*size)++;
}

void printWordFrequencies(WordFrequency words[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }
}

int main() {
    char paragraph[10000];
    WordFrequency words[MAX_WORDS];
    int size = 0;

    printf("Enter a paragraph:\n");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " \n\t,.-!?");
    while (token != NULL) {
        for (int i = 0; token[i]; i++) {
            token[i] = tolower(token[i]);
        }
        addWord(words, &size, token);
        token = strtok(NULL, " \n\t,.-!?");
    }

    printWordFrequencies(words, size);

    return 0;
}
