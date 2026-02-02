/* Write a program that prints the numbers from 1 to 100, each separated by a
newline.
If the number is a multiple of 3, it prints 'fizz' instead.
If the number is a multiple of 5, it prints 'buzz' instead.
If the number is both a multiple of 3 and a multiple of 5, it prints 'fizzbuzz' instead. */

#include <unistd.h>

int main()
{
    int i = 1, j = 0;
    char a, b;
    while (j < 10) {
        j++;
        if (j % 5 == 0) {
            write(1, "buzz\n", 5);
            continue;
        } else if (j % 3 == 0) {
            write(1, "fizz\n", 5);
            continue;
        }
        b = '0' + j;
        write(1, &b, 1);
        write(1, "\n", 1);
    }
    while (i < 10) {
        j = 0;
        a = '0' + i;
        while (j < 10) {
            j++;
            if ((10 * i + j) % 15 == 0) {
                write(1, "fizzbuzz\n", 9);
                continue;
            } else if ((10 * i + j) % 5 == 0) {
                write(1, "buzz\n", 5);
                continue;
            } else if ((10 * i + j) % 3 == 0) {
                write(1, "fizz\n", 5);
                continue;
            }
            b = '0' + j;
            write(1, &a, 1);
            write(1, &b, 1);
            write(1, "\n", 1);
        }
        i++;
    }
    return 0;
}