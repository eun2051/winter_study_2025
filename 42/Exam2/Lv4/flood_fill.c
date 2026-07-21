/* Write a function that takes a char ** as a 2-dimensional array of char, a 
t_point as the dimensions of this array and a t_point as the starting point.
Starting from the given 'begin' t_point, this function fills an entire zone 
by replacing characters inside with the character 'F'. A zone is an group of 
the same character delimitated horizontally and vertically by other characters
or the array boundry.
The flood_fill function won't fill diagonally.
The flood_fill function will be prototyped like this:
  void  flood_fill(char **tab, t_point size, t_point begin); */

#include "flood_fill.h"

void f_fill(char **tab, t_point size, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (tab[row][col] == 'F' || tab[row][col] != target)
		return ;
	tab[row][col] = 'F';

	f_fill(tab, size, target, row - 1, col);
	f_fill(tab, size, target, row + 1, col);
	f_fill(tab, size, target, row, col - 1);
	f_fill(tab, size, target, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char target = tab[begin.y][begin.x];
	f_fill(tab, size, target, begin.y, begin.x);
}
