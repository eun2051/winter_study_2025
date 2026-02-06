/* Write a program that takes a positive (or zero) number expressed in base 10,
and displays it in base 16 (lowercase letters) followed by a newline.

If the number of parameters is not 1, the program displays a newline. */
#include <unistd.h>

int	ft_atoi(char *av)
{
	int sign = 1;
	int result = 0;

	while (*av == ' ' || *av >= '\t' && *av <= '\r')
		av++;
	if (*av == '-' || *av == '+') {
		if (*av == '-')
			sign *= -1;
		av++;
	}
	while (*av >= '0' && *av <= '9') {
		result *= 10;
		result += *av - '0';
		av++;
	}
	return (sign * result);
}

void	print_hex(int	n)
{
	char c;
	char hex[] = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);
	c = hex[n % 16];
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac != 2) {
		write(1, "\n", 1);
		return 0;
	}
	int n = ft_atoi(av[1]);
	if (n == 0) {
		write(1, "0\n", 2);
		return 0;
	}
	print_hex(n);
	write(1, "\n", 1);
	return 0;
}
