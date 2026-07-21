/* Write a program that takes a string and displays it, replacing each of its
letters by the letter 13 spaces ahead in alphabetical order.
'z' becomes 'm' and 'Z' becomes 'M'. Case remains unaffected.
The output will be followed by a newline.
If the number of arguments is not 1, the program displays a newline. */
#include <unistd.h>

char find_index(char av) {
    char *s1 = "abcdefghijklmnopqrstupwxyz";
    char *s2 = "ABCDEFGHIJKLMNOPQRSTUPWXYZ";
    int i = 0;
    if (av >= 'a' && av <= 'z') {
        while (s1[i] != '\0') {
            if (av == s1[i]) {
                return s1[(i + 13) % 26];
                break;
            }
            i++;
        }
    }
    if (av >= 'A' && av <= 'Z') {
        while (s1[i] != '\0') {
            if (av == s2[i]) {
                return s2[(i + 13) % 26];
                break;
            }
            i++;
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    int i = 0;
    if (ac != 2) {
        write(1, "\n", 1);
        return 0;
    }
    char a;
    while (av[1][i] != '\0') {
        a = find_index(av[1][i]);
        if (av[1][i] >= 'a' && av[1][i] <='z') {
            write(1, &a, 1);
            i++;
            continue;
        }
        else if (av[1][i] >= 'A' && av[1][i] <= 'Z') {
            write(1, &a, 1);
            i++;
            continue;
        }
        write(1, &av[1][i], 1);
        i++;
    }
    write(1, "\n", 1);
    return 0;
}