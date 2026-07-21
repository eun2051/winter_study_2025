/* Write a program that takes a string and displays it, replacing each of its
letters by the next one in alphabetical order.
'z' becomes 'a' and 'Z' becomes 'A'. Case remains unaffected.
The output will be followed by a \n.
If the number of arguments is not 1, the program displays \n. */
#include <unistd.h>

char find_index(char av) {
    char *s1 = "abcdefghijklmnopqrstupwxyz";
    char *s2 = "ABCDEFGHIJKLMNOPQRSTUPWXYZ";
    int i = 0;
    if (av >= 'a' && av <= 'z') {
        while (s1[i] != '\0') {
            if (av == s1[i]){
                return s1[(i + 1) % 26];
            }
            i++;
        }
    }
    if (av >= 'A' && av <= 'Z') {
        while (s2[i] != '\0') {
            if (av == s2[i]) {
                return s2[(i + 1) % 26];
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
        if (av[1][i] >= 'a' && av[1][i] <= 'z') {
            a = (find_index(av[1][i]));
            write(1, &a, 1);
            i++;
            continue;
        }
        if (av[1][i] >= 'A' && av[1][i] <= 'Z') {
            a = find_index(av[1][i]);
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