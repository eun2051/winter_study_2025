#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return ;
}

void ReverseArray(int *ptr, int len)
{
    int *start = ptr;
    int *end = ptr + (len - 1);
    
    while (start < end) {
        Swap(start, end);
        start++;
        end--;
    }
}

void MaxMin(int *arr, int len, int *max, int *min)
{
    for (int i = 0; i < len; i++) {
        *max = arr[0];
        *min = arr[0];

        if (*max < arr[i])
            *max = arr[i];
        if (*min > arr[i])
            *min = arr[i];
    }
}

int main()
{
    int num1 = 100, num2 = 200;
    int arr[]= {1, 2, 3, 4, 5};
    int max, min;

    printf("num1 : %d, num2 : %d\n", num1, num2);
    Swap(&num1, &num2);
    // 매개변수가 int * 를 원함 (주소를 원하는 것임!)
    // & 연산자로 주소를 give
    printf("num1 : %d, num2 : %d\n", num1, num2);


    MaxMin(arr, 5, &max, &min);
    printf("max : %d, min : %d\n", max, min);

    ReverseArray(arr, 5);
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(arr + i));
    }
    printf("\n");

    MaxMin(arr, 5, &max, &min);
    printf("max : %d, min : %d\n", max, min);
    return 0;
}