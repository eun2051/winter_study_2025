#include <stdio.h>
#include <stdlib.h>

void reverse_cpy(void **dest, void *src)
{
    char **dst = (char **)dest;
    char *sc = (char *)src;
    int src_len = 0, i = 0;

    while (sc[i] != '\0') {
        src_len++;  
        i++;
    }
    char *tmp = (char *)malloc(sizeof(char) * (src_len + 1));
    if (tmp == NULL) {
        fprintf(stderr, "memory error\n");
        return ;
    }
    *dst = tmp;
    while (src_len - 1 >= 0) {
        *tmp = sc[src_len - 1];
        src_len--;
        tmp++;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    printf("*arr : %d\n", *arr);
    printf("*(arr + 4) : %d\n", *(arr + 4));

    // 배열 채우기
    int *arr1 = (int *)malloc(sizeof(int) * 5);
    if (arr1 == NULL) {
        fprintf(stderr, "malloc error\n");
        exit(1);
    }
    int a = 0;
    for (int i = 0; i < 5; i++) {
        *(arr + i) = a;
        a += 2;
    }

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    char *dest;
    char *src = "sleepy";

    reverse_cpy((void**)(&dest), src);
    while (*dest != '\0') {
        printf("%c ", *dest);
        dest++;
    }
    printf("\n");
    return 0;
}