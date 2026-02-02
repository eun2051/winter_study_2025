/* Write a program that takes a string and displays its first word, followed by a
newline.
A word is a section of string delimited by spaces/tabs or by the start/end of
the string.
If the number of parameters is not 1, or if there are no words, simply display
a newline. */
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int ac, char **av)
{
    if (ac > 2) {
        ft_putchar('\n');
        return 0;
    }
    int i = 0;
    while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
    while (av[1][i] != '\0') {
        if (av[1][i] == ' ' || av[1][i] == '\t')
            break;
        ft_putchar(av[1][i]);
        i++;
    }
    ft_putchar('\n');
    return 0;
}