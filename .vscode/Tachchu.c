#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 300
#define MAX_LENGTH 101

typedef struct {
    char word[MAX_LENGTH];
    int count;
} WordCount;

WordCount words[MAX_WORDS];
int wordCount = 0;

void toLowerCase(char str[]) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void addWord(char word[]) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(words[i].word, word) == 0) {
            words[i].count++;
            return;
        }
    }
    strcpy(words[wordCount].word, word);
    words[wordCount].count = 1;
    wordCount++;
}

int compare(const void *a, const void *b) {
    return strcmp(((WordCount *)a)->word, ((WordCount *)b)->word);
}

int main() {
    char text[10005];
    fgets(text, sizeof(text), stdin);

    char *token = strtok(text, " ,.-\n");
    while (token != NULL) {
        toLowerCase(token);
        addWord(token);
        token = strtok(NULL, " ,.-\n");
    }

    qsort(words, wordCount, sizeof(WordCount), compare);

    for (int i = 0; i < wordCount; i++) {
        printf("%s %d\n", words[i].word, words[i].count);
    }

    return 0;
}
