#include <stdio.h>
#include <stdlib.h>

char *find_space(char *ptr)
{
    int ptr_len = 0, i = 0;
    
    while (ptr[i] != '\0') {
        if (ptr[i] >= '\t' && ptr[i] <= '\r' || ptr[i] == ' ') {
            i++;
            continue;
        }
        ptr_len++;
        i++;
    }
    char *str = (char *)malloc(sizeof(ptr_len + 1));
    if (str == NULL) {
        fprintf(stderr, "malloc error\n");
        return (NULL);
    }
    char *tmp = str;
    while (*ptr != '\0') {
        if (*ptr >= '\t' && *ptr <= '\r' || *ptr == ' ')
            ptr++;
        *tmp = *ptr;
        ptr++;
        tmp++;
    }
    *tmp = '\0';
    return (str);
}

int main()
{
    char word[100];
    char *ptr = word;

    printf("word : ");
    scanf("%[^\n]s", word);
    printf("%s", find_space(ptr));
    return 0;
}