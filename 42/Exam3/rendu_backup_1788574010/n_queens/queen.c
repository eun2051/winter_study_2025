#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_sol(int *board, int n)
{
	int i = 0;

	while (i < n)
	{
		fprintf(stdout, "%d", board[i]);
		if (i != n - 1)
			fprintf(stdout, " ");
		i++;
	}
	fprintf(stdout, "\n");
}

int	is_safe(int *board, int col, int row)
{
	int i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return 0;
		if (row - board[i] == col - i || board[i] - row == col - i)
			return 0;
		i++;
	}
	return 1;
}

void	solve_n_queens(int *board, int n, int curr_col)
{
	if (curr_col == n)
	{
		print_sol(board, n);
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
		return 1;
	int n = atoi(av[1]);
	if (n <= 0)
		return 0;
	int *board = (int *)malloc(sizeof(int) * (n + 1));
	solve_n_queens(board, n, 0);
	free(board);
	return 0;
}
