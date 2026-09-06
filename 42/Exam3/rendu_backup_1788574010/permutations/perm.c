#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int	get_len(char *str)
{
	int len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return len;
}

void	sort_alpha(char *str, int len)
{
	int i = 0;
	while (i < len)
	{
		int j = i + 1;
		while (j < len)
		{
			if (str[i] > str[j])
			{
				char tmp = str[i];
				str[i] = str[j];
				str[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	generate_perm(char *str, char *res, int *used, int len, int depth)
{
	if (depth == len)
	{
		res[depth] = '\0';
		puts(res);
		return;
	}
	int i = 0;
	while (i < len)
	{
		if (used[i] == 0)
		{
			used[i] = 1;
			res[depth] = str[i];
			generate_perm(str, res, used, len, depth + 1);
			used[i] = 0;
		}
		i++;
	}

}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int len = get_len(av[1]);
	sort_alpha(av[1], len);
	char *res = (char *)malloc(sizeof(char) * (len + 1));
	int *used = (int *)calloc(len + 1, sizeof(int));
	if (!res || !used)
	{
		free(res);
		free(used);
		return (1);
	}
	generate_perm(av[1], res, used, len, 0);
	free(res);
	free(used);
	return 0;
}
