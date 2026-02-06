/* Write a program that takes a positive int and displays its prime factors on the
standard output, followed by a newline.

Factors must be displayed in ascending order and separated by '*', so that
the expression in the output gives the right result.

If the number of parameters is not 1, simply display a newline.

The input, when there is one, will be valid. */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac != 2) {
		printf("\n");
		return 0;
	}
	int	pos = atoi(av[1]);
	int	i = 2;
	if (pos == 1) {
		printf("1\n");
		return 0;
	}
	while (i <= pos) {
		if (pos % i == 0) {
			printf("%d", i);
			if (i < pos)
				printf("*");
			pos /= i;
		} else
			i++;
	}
	printf("\n");
	return 0;	
}
