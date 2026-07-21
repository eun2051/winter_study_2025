/* Write a program that takes two strings representing two strictly positive
integers that fit in an int.

Display their highest common denominator followed by a newline (It's always a
strictly positive integer).

If the number of parameters is not 2, display a newline. */
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac != 3) {
        printf("\n");
        return 0;
    }
    int a1 = atoi(av[1]);
    int a2 = atoi(av[2]);
    int result = 0, i = 0;
    while (i <= a1 && i <= a2) {
        if (a1 % i == 0 && a2 % i == 0) {
            result = i;
        }
        i++;
    }
    printf("%d\n", result);
    return 0;
}