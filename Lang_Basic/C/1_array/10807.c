// 총 N개의 정수가 주어졌을 때, 정수 V가 몇 개인지 구하는 프로그램

#include <stdio.h>

int main(void)
{
	int	N, v;
	int	num = 0;
	int	arr[100];

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
	scanf("%d", &arr[i]);
	}
	scanf("%d", &v);
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == v)
			num++;
	}
	printf("%d", num);
	return (0);
}
