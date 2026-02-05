/* Write a program that takes two strings and displays, without doubles, the
characters that appear in either one of the strings.

The display will be in the order characters appear in the command line, and
will be followed by a \n.

If the number of arguments is not 2, the program displays \n. */

#include <unistd.h>

int	ft_check(char *str, char c, int len)
{
	int i = 0;
	while (i < len) {
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int	ft_strlen(char *str)
{
	int len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

int main(int ac, char **av)
{
	if (ac != 3) {
		write(1, "\n", 1);
		return 0;
	}
	int len_1 = ft_strlen(av[1]);
	int i = 0;
	while (av[1][i] != '\0') {
		if (!ft_check(av[1], av[1][i], i))
			write(1, &av[1][i], 1);
		i++;
	}
	i = 0;
	while (av[2][i] != '\0') {
		if (!ft_check(av[1], av[2][i], len_1) && !ft_check(av[2], av[2][i], i)) {
			write(1, &av[2][i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}