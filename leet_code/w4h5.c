#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 16

char dictionary[MAX_WORDS][MAX_LEN];
int dict_size = 0;

int is_word_in_dictionary(char *word) {
    for (int i = 0; i < dict_size; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int can_split(char *str) {
    int len = strlen(str);
    if (len == 0) {
        return 1;
    }

    for (int i = 1; i <= len; i++) {
        char prefix[i + 1];
        strncpy(prefix, str, i);
        prefix[i] = '\0';

        if (is_word_in_dictionary(prefix) && can_split(str + i)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char str[101];
    scanf("%s", str);
    while (1) {
        char word[MAX_LEN];
        scanf("%s", word);
        if (strcmp(word, "END") == 0) {
            break;
        }
        strcpy(dictionary[dict_size++], word);
    }

    if (can_split(str)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
