/* Write a program that takes a string and displays this string after rotating it
one word to the left.

Thus, the first word becomes the last, and others stay in the same order.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

Words will be separated by only one space in the output.

If there's less than one argument, the program displays \n. */

#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac < 2) {
		write(1, "\n", 1);
		return 0;
	}
	int flag = 0;
	int i = 0, j = 0;
	int start, len = 1;
	while (av[1][i] == ' ' || av[1][i] == '\t')
		i++;
	start = i;
	while (av[1][i + 1] != ' ' && av[1][i + 1] != '\t' && av[1][i + 1] != '\0')
		i++;
	len = i - start + 1;
	char *str = (char *)malloc(len + 1);
	while (start <= i) {
		str[j] = av[1][start];
		start++;
		j++;
	}
	str[j] = '\0';
	i++;
	while (av[1][i] == ' ' || av[1][i] == '\t')
		i++;
	while (av[1][i] != '\0') {
		if (av[1][i] == ' ' || av[1][i] == '\t') {
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
			write(1, " ", 1);
			write(1, &av[1][i], 1);
			i++;
			continue;
		}
		write(1, &av[1][i], 1);
		i++;
		flag++;
	}
	j = 0;
	if (flag > 0)
		write(1, " ", 1);
	while (str[j] != '\0') {
		write(1, &str[j], 1);
		j++;
	}
	write(1, "\n", 1);
	free(str);
	return 0;
}
