/* Write a program that takes a string and displays it with exactly three spaces
between each word, with no spaces or tabs either at the beginning or the end,
followed by a newline.

A word is a section of string delimited either by spaces/tabs, or by the
start/end of the string.

If the number of parameters is not 1, or if there are no words, simply display
a newline. */
#include <unistd.h>

int ft_strlen(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return len;
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write(1, "\n", 1);
        return 0;
    }
    int i = 0;
    int end = ft_strlen(av[1]) - 1;
    while (av[1][i] == ' ' || av[1][i] == '\t')
        i++;
    while (av[1][end] == ' ' || av[1][end] == '\t')
        end--;
    while (i <= end) {
        if (av[1][i] == ' ' || av[1][i] == '\t') {
            while (av[1][i + 1] == ' ' || av[1][i + 1] == '\t')
                i++;
            write(1, "   ", 3);
            i++;
        }
        write(1, &av[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return 0;
}