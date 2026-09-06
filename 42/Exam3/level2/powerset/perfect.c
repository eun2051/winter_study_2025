#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

void	find_subset(int *set, int *subset, int set_size, int i, int sub_size, int curr_sum, int target_sum)
{
	if (i == set_size)
	{
		if (curr_sum == target_sum)
		{
			for (int j = 0; j < sub_size; j++)
			{
				if (j == 0)
					printf("%d", subset[j]);
				else
					printf(" %d", subset[j]);
			}
			printf("\n");
		}
		return ;
	}
	find_subset(set, subset, set_size, i + 1, sub_size, curr_sum, target_sum);
	subset[sub_size] = set[i];
	find_subset(set, subset, set_size, i + 1, sub_size + 1, curr_sum + set[i], target_sum);
}

int main(int ac, char **av)
{
	if (ac < 3)
		return (1);
	int sum = atoi(av[1]);
	int size = ac - 2;

	int *set = (int *)malloc(sizeof(int) * (size + 1));
	int	*subset = (int *)malloc(sizeof(int) * (size + 1));
	if (set == NULL || subset == NULL)
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
	return (0);
}

