//바구니를 총 N개 가지고 있고, 각각의 바구니에는 1번부터 N번까지 번호가 매겨져 있다
//앞으로 M번 공을 바꾸려고 한다. 공을 바꿀 바구니 2개를 선택하고 두 바구니에 들어있는 공을 서로 교환
//공을 어떻게 바꿀지가 주어졌을 때, M번 공을 바꾼 이후에 각 바구니에 어떤 공이 들어있는지 구하는 프로그램

#include <stdio.h>

int main()
{
    int N, M;
    int i, j, temp;
    int arr[100];

    scanf("%d %d", &N, &M);
    for (int index = 1; index <= N; index++)
        arr[index] = index;
    for (int count = 0; count < M; count++)
    {
        scanf("%d %d", &i, &j);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    for (int index = 1; index <= N; index++)
        printf("%d ", arr[index]);
}