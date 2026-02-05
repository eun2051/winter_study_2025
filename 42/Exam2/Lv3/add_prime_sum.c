/* Write a program that takes a positive integer as argument and displays the sum
of all prime numbers inferior or equal to it followed by a newline.

If the number of arguments is not 1, or the argument is not a positive number,
just display 0 followed by a newline. */
#include <unistd.h>

int ft_atoi(char *str)
{
    int sign = 1;
    int result = 0;

    while (*str == ' ' || *str >= '\t' && *str <= '\r')
        str++;
    if (*str == '-' || *str == '+') {
        if (*str == '-')
            sign *= -1;
        str++;
    }
    while (*str >= '0' && *str <= '9') {
        result *= 10;
        result += *str - '0';
        str++;
    }
    return (sign * result);
}

void    ft_putnbr(int nb)
{
    char c;
    long long n = nb;

    if (n < 0) {
        n = -n;
        write(1, "-", 1);
    } 
    if (n > 9)
        ft_putnbr(n / 10);
    c = '0' + (n % 10);
    write(1, &c, 1);
}

int check_prime(int a) {
    if (a == 0 || a == 1)
        return 0;
    int i = 2;
    while (i < a) {
        if (a % i == 0) {
            return 0;
        }
        i++;
    }
    return a;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write(1, "0", 1);
        write(1, "\n", 1);
        return 0;
    }
    int a = ft_atoi(&av[1][0]);
    if (a < 0)  {
        write(1, "0", 1);
        write(1, "\n", 1);
        return 0;
    }
    int sum = 0;
    while (a > 0) {
        sum += check_prime(a);
        a--;
    }
    ft_putnbr(sum);
    write(1, "\n", 1);
    return 0;
}