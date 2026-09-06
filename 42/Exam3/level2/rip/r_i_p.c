#include <unistd.h>
#include <stdio.h>

void	solve(char *str, int i, int left_rm, int right_rm, int cnt)
{
	if (str[i] == '\0')
	{
		if (left_rm == 0 && right_rm == 0 && cnt == 0)
			puts(str);
		return ;
	}
	if (str[i] == '(')
	{
		if (left_rm > 0)
		{
			str[i] = ' ';
			solve(str, i + 1, left_rm - 1, right_rm, cnt);
			str[i] = '(';
		}
		solve(str, i + 1, left_rm, right_rm, cnt + 1);
		return ;
	}
	if (str[i] == ')')
	{
		if (right_rm > 0)
		{
			str[i] = ' ';
			solve(str, i + 1, left_rm, right_rm - 1, cnt);
			str[i] = ')';
		}
		if (cnt > 0)
			solve(str, i + 1, left_rm, right_rm, cnt - 1);
		return ;
	}
	solve(str, i + 1, left_rm, right_rm, cnt);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int left_rm = 0;
	int right_rm = 0;
	int i = 0;
	while (av[1][i] != '\0')
	{
		if (av[1][i] == '(')
			left_rm++;
		if (av[1][i] == ')')
		{
			if (left_rm > 0)
				left_rm--;
			else
				right_rm++;
		}
		i++;
	}
	solve(av[1], 0, left_rm, right_rm, 0);
	return (0);
}
