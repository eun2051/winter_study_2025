/* Write a program that takes two strings and displays, without doubles, the characters that appear in both strings, in the order they appear in the first one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n. */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

int	check_char(char *str, char c)
{
	int i = 0, j;
	int len = ft_strlen(str);
	while (str[i] != '\0') {
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}

int main(int ac, char **av)
{
	if (ac != 3) {
		write(1, "\n", 1);
		return 0;
	}
	int	i = 0, j;
	while (av[1][i] != '\0') {
		j = 0;
		while (av[2][j] != '\0') {
			if (!check_char(av[2], av[2][j]) || !check_char(av[1], av[1][i]))
				break;
			if (av[1][i] == av[2][j]) {
				write(1, &av[2][j], 1);
				break;
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
