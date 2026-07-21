/* Write a program that takes one or several strings and, for each argument,
capitalizes the first character of each word (If it's a letter, obviously),
puts the rest in lowercase, and displays the result on the standard output,
followed by a \n.

A "word" is defined as a part of a string delimited either by spaces/tabs, or
by the start/end of the string. If a word only has one letter, it must be
capitalized.

If there are no arguments, the progam must display \n. */
#include <unistd.h>

void ft_change(char av)
{
    if (av >= 'A' && av <= 'Z') {
        av += 32;
        write(1, &av, 1);
    } else if (av >= 'a' && av <= 'z') {
        av -= 32;
        write(1, &av, 1);
    } else
        write(1, &av, 1);
}

int main(int ac, char **av)
{
    if (ac < 2) {
        write(1, "\n", 1);
        return 0;
    }
    int i, end = 0, j = 1;
    while (j < ac) {
        i = 0;
        while (av[j][i] == ' ' || av[j][i] == '\t')
            i++;
        if (av[j][i] >= 'a' && av[j][i] <= 'z')
            ft_change(av[j][i]);
        else    
            write(1, &av[j][i], 1);
        i++;
        while (av[j][i] != '\0') {
            if (av[j][i] == ' ' || av[j][i] == '\t') {
                while (av[j][i] == ' ' || av[j][i] == '\t') {
                    write(1, &av[j][i], 1);
                    i++;
                }
                if (av[j][i] >= 'a' && av[j][i] <= 'z')
                    ft_change(av[j][i]);
                else
                    write(1, &av[j][i], 1);
                i++;
                continue;
            }
            if (av[j][i] >= 'A' && av[j][i] <= 'Z') {
                ft_change(av[j][i]);
                i++;
                continue;
            }
            write(1, &av[j][i], 1);
            i++;
        }
        j++;
        write(1, "\n", 1);
    }
    return 0;
}