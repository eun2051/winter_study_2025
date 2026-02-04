/* Write a program that takes three strings:
- The first and the third one are representations of base-10 signed integers
  that fit in an int.
- The second one is an arithmetic operator chosen from: + - * / %

The program must display the result of the requested arithmetic operation,
followed by a newline. If the number of parameters is not 3, the program
just displays a newline.

You can assume the string have no mistakes or extraneous characters. Negative
numbers, in input or output, will have one and only one leading '-'. The
result of the operation fits in an int. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac != 4) {
		write(1, "\n", 1);
		return 0;
	}
	int	a = atoi(av[1]);
	int	b = atoi(av[3]);
	int	result = 0;
	if (av[2][0] == '+')
	{
		result = a + b;
	}
	if (av[2][0] == '-')
	{
		result = a - b;
	}
	if (av[2][0] == '*')
	{
		result = a * b;
	}
	if (av[2][0] == '/')
	{
		result = a / b;
	}
	if (av[2][0] == '%')
	{
		result = a % b;
	}
	printf("%d\n", result);
	return 0;
}
