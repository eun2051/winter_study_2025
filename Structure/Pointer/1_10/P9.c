#include <stdio.h>
#include <stdlib.h>

void mem_set(int *arr, int size)
{
    char *array = (char *)arr; 
    
    for (int i = 0; i < size; i++) {
        array[i] = 0xFF;
    }
}

int main()
{
    int arr[7] = {1, 5, 8, 3, 7, 9, 2};
    int arr_size = (sizeof(arr));
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    mem_set(arr, arr_size);
    for (int i = 0; i < 7; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}