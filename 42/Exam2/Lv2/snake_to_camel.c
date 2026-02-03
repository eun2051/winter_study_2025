/* Write a program that takes a single string in snake_case format
and converts it into a string in lowerCamelCase format.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one. */

#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int	i = 0;
	char	a;
	while (av[1][i] != '\0')
	{
		if (av[1][i] == '_') {
			i++;
			a = av[1][i] - 32;
			write(1, &a, 1);
			i++;
			continue;
		}
		write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
