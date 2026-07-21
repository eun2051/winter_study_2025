//N개의 정수가 주어진다. 이때 최솟값과 최댓값을 구하는 프로그램을 작성

#include <stdio.h>
int	n[1000000];

int	main(void)
{
	int	N;
	int max, min;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &n[i]);
	}
	max = n[0];
	min = n[0];
	for (int i = 1; i < N; i++)
	{
		if (n[i] > max)
			max = n[i];
		if (n[i] < min)
			min = n[i];
	}
	printf("%d %d", min, max);
	return 0;
}
