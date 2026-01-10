#include <stdio.h>

void change(char *pt)
{
    while (*pt != '\0') {
        if (*pt >= 'a' && *pt <= 'z')
            *pt -= 32;
        else if (*pt >= 'A' && *pt <= 'z')
            *pt += 32;
        pt++;
    }
}

char *MyStrChr(char *ptr)
{
    while (*ptr != '\0') {
        if (*ptr == 'a') {
            return (ptr);
        }
        ptr++;
    }
    return (NULL);
}

int main()
{
    char word[100];
    char *ptr = word;

    printf("word : ");
    scanf("%s", word);

    printf("%p\n", MyStrChr(ptr));
    change(ptr);
    printf("%s\n", word);
    return 0;
}