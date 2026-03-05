/* Write a program that takes one or more strings and, for each argument, puts
the last character that is a letter of each word in uppercase and the rest
in lowercase, then displays the result followed by a \n.

A word is a section of string delimited by spaces/tabs or the start/end of the
string. If a word has a single letter, it must be capitalized.

A letter is a character in the set [a-zA-Z]

If there are no parameters, display \n. */
#include <unistd.h>

int	ft_strlen(char *av)
{
	int len = 0;

	while (av[len] != '\0')
		len++;
	return len;
}

int main(int ac, char **av)
{
	if (ac < 2) {
		write(1, "\n", 1);
		return 0;
	}
	int i, j = 1;
	char c;
	while (j < ac) {
		i = 0;
		while (av[j][i] == ' ' || av[j][i] == '\t')
			i++;
		while (av[j][i] != '\0') {
			if (av[j][i + 1] == ' ' || av[j][i + 1] == '\t' || av[j][i + 1] == '\0') {
				if (av[j][i] >= 'a' && av[j][i] <= 'z') {
					c = av[j][i] - 32;
					write(1, &c, 1);
				} else
					write(1, &av[j][i], 1);
				i++;
				continue;
			}
			if (av[j][i] >= 'A' && av[j][i] <= 'Z') {
				c = av[j][i] + 32;
				write(1, &c, 1);
			} else write(1, & av[j][i], 1);
			i++;
		}
		j++;
		write(1, "\n", 1);
	}
	return 0;
}
