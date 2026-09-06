#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void	print_solution(int *board, int n)
{
	for (int i = 0; i < n; i++)
	{
		fprintf(stdout, "%d", board[i]);
		if (i != n-1)
			fprintf(stdout, " ");
	}
	fprintf(stdout, "\n");
}

int	is_safe(int *board, int curr_col, int test_row)
{
	int i = 0;
	while (i < curr_col)
	{
		if (board[i] == test_row)
			return (0);
		if (test_row - board[i] == curr_col - i ||
				board[i] - test_row == curr_col - i)
			return (0);
		i++;
	}
	return (1);
}

void	solve_n_queens(int *board, int n, int curr_col)
{
	if (curr_col == n)
	{
		print_solution(board, n);
		return ;
	}
	int i = 0;
	while (i < n)
	{
		if (is_safe(board, curr_col, i) == 1)
		{
			board[curr_col] = i;
			solve_n_queens(board, n, curr_col + 1);
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int n = atoi(av[1]);
	if (n <= 0)
		return (0);
	int *board = (int *)malloc(sizeof(int) * (n + 1));
	if (board == NULL)
		return (0);
	solve_n_queens(board, n, 0);
	free(board);
	return (0);
}
