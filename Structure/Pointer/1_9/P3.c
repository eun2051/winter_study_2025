#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[] = "i don't give up";
    char *ptr = str;
    int len = 0;

    while (*ptr != '\0') {
        ptr++;
        len++;
    }
    printf("length : %d\n", len);
    return 0;
}