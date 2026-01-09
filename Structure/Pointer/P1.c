#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[3] = {10, 20, 30};

    printf("array name : %p\n", arr);
    printf("array first place : %p\n", &arr[0]);
    printf("array all address: %p\n", &arr);

    int *ptr = arr;

    for (int i = 0; i < 3; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    // 왜 정수로 출력해야할까?
    // (ptr + i) 는 주소이지만 *(ptr + i)는 값이다.
    printf("*(ptr + 1) : %d\n", *(ptr + 1));
    printf("*ptr + 1 : %d\n", *ptr + 1);

    //증감 연산자s
    printf("first place : %p, first value : %d\n", ptr, *ptr);

    int val1 = *ptr++;
    // 참조먼저 -> ++ 됨
    // 결과적으로 val1와 val2sms ehddlfgkek
    printf("*ptr++ place : %p, *ptr++ value : %d\n", (ptr++), val1);

    ptr = arr;
    int val2 = (*ptr)++;
    printf("(*ptr)++ place : %p, (*ptr)++ value : %d\n", &val2, val2);

    //*(ptr++); 괄호로 인해 ++ 먼저 -> 역참조
    return 0;
}