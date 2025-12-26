//정수 N개로 이루어진 수열 A와 정수 X가 주어진다
//이때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성
#include <stdio.h>

int	main(void)
{
	int	N, X;
	int	A[10000];

	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &A[i]);	
	}
	for (int i = 0; i < N; i++)
	{
		if (A[i] < X)
			printf("%d ", A[i]);
	}
	return 0;
}
