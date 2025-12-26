//바구니를 총 N개 가지고 있고, 각각의 바구니에는 1번부터 N번까지 번호가 매겨져 있다
//가장 처음 바구니에는 공이 들어있지 않으며, 바구니에는 공을 1개만 넣을 수 있다
//앞으로 공을 M번 넣으려고 한다. 한번 공을 넣을 때, 공을 넣을 바구니 범위를 정하고
//정한 바귀니에 모두 같은 번호가 적혀있는 공을 넣는다
//만약 바구니에 공이 이미 있는 경우 있는 공을 뺴고 새로 공을 넣는다
// 공을 넣을 바구니는 연속되어 있어야한다

// 공을 어떻게 넣을지가 주어졌을때, M번 공을 넣은 이후에 각 바구니에 어떤 공이
// 들어있는지 구하는 프로그램 작성하기

#include <stdio.h>

int main()
{
    int N, M;
    int i, j ,k;
    int arr[100] = {0, };

    scanf("%d %d", &N, &M);
    for (int count = 0; count < M; count++)
    {
        scanf("%d %d %d", &i, &j, &k);
        for (int index = i; index <= j; index++)
            arr[index] = k;
    }
    for (int dex = 1; dex <= N; dex++)
        printf("%d ", arr[dex]);
    return 0;
}