/* Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n. */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 3) {
		write(1, "\n", 1);
		return 0;
	}
	int i = 0, j;
	while (av[2][i] != '\0') {
		j = 0;
		while (av[1][j] != '\0') {
			if (av[1][j] != av[2][i])
		}
	}
	write(1, "\n", 1);
	return 0;
}