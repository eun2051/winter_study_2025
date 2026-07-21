//9개의 서로 다른 자연수가 주어질 때, 이들 중 최댓값을 찾고 그 최댓값이
//몇번째 수인지를 구하는 프로그램을 작성
#include <stdio.h>

int main(void)
{
    int index;
    int max;
    int arr[9];

    for (int i = 0; i < 9; i++)
        scanf("%d", &arr[i]);
    max = arr[0];
    index = 0;
    for (int i = 1; i < 9; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i;
        }
    }
    printf("%d\n", max);
    printf("%d", index + 1);
    return 0;
}