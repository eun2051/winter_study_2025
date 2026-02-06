/* Write a program that takes a string as a parameter, and prints its words in
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the
begin/end of the string.

If the number of parameters is different from 1, the program will display
'\n'.

In the parameters that are going to be tested, there won't be any "additional"
spaces (meaning that there won't be additionnal spaces at the beginning or at
the end of the string, and words will always be separated by exactly one space). */
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *av)
{
	int len = 0;

	while (av[len] != '\0')
		len++;
	return len;
}

int main(int ac, char **av)
{
	if (ac != 2) {
		write(1, "\n", 1);
		return 0;
	}
	int start = 0, end = 0;
	int i = ft_strlen(av[1]) - 1;
	while (i >= 0) {
		while (i >= 0 && (av[1][i] == ' ' || av[1][i] == '\t'))
			i--;
		if (i < 0)
			break;
		end = i;
		while (i >= 0 && (av[1][i] != ' ' && av[1][i] != '\t'))
			i--;
		start = i + 1;
		while (start <= end) {
			write(1, &av[1][start], 1);
			start++;
		}
		if (i >= 0)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	return 0;
}
