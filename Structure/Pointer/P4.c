#include <stdio.h>
#include <stdlib.h>

int main()
{
    char word[100];
    char *start = word;
    int len = 0;

    printf("enter word : ");
    scanf("%s", word);
    while (*start != '\0') {
        start++;
        len++;
    }
    start = word;
    int half = len % 2;
    while (half >= 0) {
        if (*start != word[len - 1]) {
            fprintf(stderr, "wrong\n");
            return 1;
        }
        start++;
        half--;
        len--;
    }
    printf("%s", word);
    return 0;
}