/* Write a program that displays a number's multiplication table.

The parameter will always be a strictly positive number that fits in an int,
and said number times 9 will also fit in an int.

If there are no parameters, the program displays \n. */
#include <unistd.h>

int    ft_atoi(char *av)
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

void ft_putnbr(int nb)
{
    char c;
    long long n = nb;
    if (n < 0) {
        n = -n;
        write(1, "-", 1);
    }
    if (n > 9) {
        ft_putnbr(n / 10);
    }
    c = '0' + (n % 10);
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    if (ac < 2) {
        write(1, "\n", 1);
        return 0;
    }
    int a = ft_atoi(av[1]);
    int i = 1;
    int mul = 0;
    while (i < 10) {
        mul = i * a;
        ft_putnbr(i);
        write(1, " x ", 3);
        ft_putnbr(a);
        write(1, " = ", 3);
        ft_putnbr(mul);
        write(1, "\n", 1);
        i++;
    }
    return 0;
}