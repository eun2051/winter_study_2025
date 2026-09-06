#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void solve(char *str, int i, int left, int right, int cnt)
{
	if (str[i] == '\0')
	{
		if (left == 0 && right == 0 && cnt == 0)
			puts(str);
		return ;
	}
	if (str[i] == '(')
	{
		if (left > 0)
		{
			str[i] = ' ';
			solve(str, i + 1, left - 1, right, cnt);
			str[i] = '(';
		}
		solve(str, i + 1, left, right, cnt + 1);
		return ;
	}
	if (str[i] == ')')
	{
		if (right > 0)
		{
			str[i] = ' ';
			solve(str, i + 1, left, right - 1, cnt);
			str[i] = ')';
		}
		if (cnt > 0)
			solve(str, i + 1, left, right, cnt - 1);
		return ;
	}
	solve(str, i + 1, left, right, cnt);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int i = 0;
	int left = 0;
	int right = 0;

	while (av[1][i] != '\0')
	{
		if (av[1][i] == '(')
			left++;
		if (av[1][i] == ')')
		{
			if (left > 0)
				left--;
			else
				right++;
		}
		i++;
	}
	solve(av[1], 0, left, right, 0);
	return 0;
}
