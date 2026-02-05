/* Write a program named hidenp that takes two strings and displays 1
followed by a newline if the first string is hidden in the second one,
otherwise displays 0 followed by a newline.

Let s1 and s2 be strings. We say that s1 is hidden in s2 if it's possible to
find each character from s1 in s2, in the same order as they appear in s1.
Also, the empty string is hidden in any string.

If the number of parameters is not 2, the program displays a newline. */
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac != 3) {
        write(1, "\n", 1);
        return 0;
    }
    int i = 0, j = 0;
    while (av[2][i] != '\0') {
        if (av[1][j] == av[2][i])
            j++;
        i++;
    }
    if (av[1][j] == '\0')
        write(1, "1", 1);
    else
        write(1, "0", 1);
    write(1, "\n", 1);
    return 0;
}