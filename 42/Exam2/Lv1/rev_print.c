/* Write a program that takes a string, and displays the string in reverse
followed by a newline.
If the number of parameters is not 1, the program displays a newline. */
#include <unistd.h>

int ft_strlen(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return (len);
}

int main(int ac, char **av) {
    if (ac != 2) {
        write(1, "\n", 1);
        return 0;
    }
    int av_l = ft_strlen(av[1]);
    while (av_l > 0) {
        write(1, &av[1][av_l - 1], 1);
        av_l--;
    }
    write(1, "\n", 1);
    return 0;
}