#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void	*work_thread(void *num);

typedef struct a
{
	int start;
	int end;
} aa;


int main(void)
{
	pthread_t threa;
	aa	num;

	float	t1;
	float	t2;
	float	t3;
	float	t4;
	float	*res = 0;
	float	sum;
	num.start = 0;
	num.end = 2499;
	
	pthread_create(&threa, NULL, work_thread, &num);
	pthread_join(threa, (void **)&res);
	t1 = *res;
	printf("t1 = %f\n", t1);
	pthread_create(&threa, NULL, work_thread, &num);
	num.start = 2500;
	num.end = 4999;
	pthread_join(threa, (void **)&res);
	t2 = *res;
	pthread_create(&threa, NULL, work_thread, &num);
	num.start = 5000;
	num.end = 7499;
	pthread_join(threa, (void **)&res);
	t3 = *res;
	pthread_create(&threa, NULL, work_thread, &num);
	num.start = 7500;
	num.end = 9999;
	pthread_join(threa, (void **)&res);
	t4 = *res;
	sum = t1 + t2 + t3 + t4;
	printf("value: %f\n", sum);
	return (0);
}

void	*work_thread(void *num)
{
	aa	*ptr = (aa *)num;
	float	*nm;

	nm = (float *)malloc(sizeof(float));
	*nm = 0;
	for (int i = ptr->start; i <= ptr->end; i++)
		*nm += 1.0;
	printf("nm = %f\n", *nm);
	pthread_exit(nm);
}
