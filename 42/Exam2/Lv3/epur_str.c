/* Write a program that takes a string, and displays this string with exactly one
space between words, with no spaces or tabs either at the beginning or the end,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string.

If the number of arguments is not 1, or if there are no words to display, the
program displays \n. */
#include <unistd.h>
#include <stdio.h>

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
        if (av[1][i] == '\t' || av[1][i] == ' ') {
            while (av[1][i + 1] == '\t' || av[1][i + 1] == ' ')
                i++;
            write(1, " ", 1);
            i++;
        }
        write(1, &av[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return 0;
}