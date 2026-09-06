#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void find_subset(int *set, int *subset, int size, int i, int sub_size, int curr_sum, int target_sum)
{
	if (i == size)
	{
		if (curr_sum == target_sum)
		{
			int j = 0;
			while (j < sub_size)
			{
				if (j == 0)
					fprintf(stdout, "%d", subset[j]);
				else
					fprintf(stdout, " %d", subset[j]);
				j++;
			}
			fprintf(stdout, "\n");
		}
		return ;
	}
	find_subset(set, subset, size, i + 1, sub_size, curr_sum, target_sum);
	subset[sub_size] = set[i];
	find_subset(set, subset, size, i + 1, sub_size + 1, curr_sum + set[i], target_sum);
}

int main(int ac, char **av)
{
	if (ac < 3)
		return 1;
	int sum = atoi(av[1]);
	int size = ac - 2;
	int *set = (int *)malloc(sizeof(int) * (size + 1));
	int *subset = (int *)malloc(sizeof(int) * (size + 1));
	if (!set || !subset)
	{
		free(set);
		free(subset);
		exit(1);
	}
	int i = 0;
	while (i < size)
	{
		set[i] = atoi(av[i + 2]);
		i++;
	}
	find_subset(set, subset, size, 0, 0, 0, sum);
	free(set);
	free(subset);
	return 0;
}
