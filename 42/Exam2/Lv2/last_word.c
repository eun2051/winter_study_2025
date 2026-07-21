/* Write a program that takes a string and displays its last word followed by a \n.

A word is a section of string delimited by spaces/tabs or by the start/end of
the string.

If the number of parameters is not 1, or there are no words, display a newline. */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int len = 0;
	while (str[len] != '\0') {
		len++;
	}
	return len;
}

int main(int ac, char **av)
{
	if (ac != 2) {
		write(1, "\n", 1);
		return 0;
	}
	int end = ft_strlen(av[1]) - 1;
	int start = 0;
	int last = 0;
	while (av[1][end] == ' ' || av[1][end] == '\t')
		end--;
	last = end;
	while (end >= 0) {
		if (av[1][end] == ' ' || av[1][end] == '\t')
			break;
		end--;
	}
	while (end < last) {
		write(1, &av[1][end + 1], 1);
		end++;
	}
	write(1, "\n", 1);
	return 0;
}
