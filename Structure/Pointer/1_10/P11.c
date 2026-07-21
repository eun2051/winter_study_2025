#include <stdio.h>
#include <stdlib.h>

void SwapString(char **a, char **b)
{
    char *tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    char *s1 = malloc(100);
    char *s2 = malloc(100);

    printf("get string 1: ");
    fgets(s1, (sizeof(s1)), stdin);
    printf("get string 2: ");
    fgets(s2, (sizeof(s2)), stdin);

    printf("%s, %s", s1, s2);
    SwapString(&s1, &s2);
    printf("%s, %s", s1, s2);
    free(s1);
    free(s2);
}