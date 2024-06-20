//Pattern Matching

#include <stdio.h>
#include <string.h>

int substringMatch(const char *text, const char *pattern) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);

    for (int i = 0; i <= textLen - patternLen; i++) {
        int j;
        for (j = 0; j < patternLen; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == patternLen)
            return i; // substring found at index i
    }
    return -1; // substring not found
}

int main() {
    char text[100], pattern[100];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern to match: ");
    scanf("%s", pattern);

    int position = substringMatch(text, pattern);

    if (position != -1)
        printf("Pattern found at position: %d\n", position);
    else
        printf("Pattern not found in the text.\n");

    return 0;
}
