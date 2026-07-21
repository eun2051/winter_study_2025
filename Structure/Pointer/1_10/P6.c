#include <stdio.h>

int main()
{
    //최대값 주소
    int arr[7] = {2, 5, 4, 7, 8, 9, 1};
    int max = arr[0];
    int end = (sizeof(arr)) / (sizeof(int));

    printf("end : %d\n", end);

    for (int i = 1; i <= 7; i++) {
        if (max < arr[i])
            max = arr[i];
    }
    printf("value : %d, addr : %p\n", max, &max);

    //짝수만 0으로 
    for (int i = 0; i < 7; i++) {
        if ((arr[i]) % 2 == 0)
            arr[i] = 0;
    }

    for(int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    //포인터 뺄셈
    //배열의 첫 번째 원소 주소와 마지막 원소 주소를 뺸 결과
    int *ptr_end = &arr[end];
    int *ptr_start = &arr[0];
    printf("ptr_end : %p\n", ptr_end);
    printf("ptr_start : %p\n", ptr_start);
    printf("min : %ld\n", ptr_end - ptr_start);

    return 0;
}