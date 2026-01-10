#include <stdio.h>
#include <stdlib.h>

int count_word(char *str)
{
    int count = 1, i = 0;

    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            count++;
        i++;
    }
    return (count);
}

int main()
{
    char str[100];
    printf("get string : ");
    fgets(str, sizeof(str), stdin);

    printf("string : %s", str);
    printf("word : %d", count_word(str));
    return 0;
}