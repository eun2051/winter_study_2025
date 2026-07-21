/* Write a program that displays the number of arguments passed to it, followed by
a newline.

If there are no arguments, just display a 0 followed by a newline. */
#include <unistd.h>

void    ft_putnbr(int nb)
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
    c = '0' + (n  % 10);
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    if (ac < 2) {
        write(1, "0\n", 2);
        return 0;
    }
    int ag = ac - 1;
    ft_putnbr(ag);
    write(1, "\n", 1);
    return 0;
}