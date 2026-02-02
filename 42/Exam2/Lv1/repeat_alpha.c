/* Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.
'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...
Case remains unchanged.
If the number of arguments is not 1, just display a newline. */
#include <unistd.h>

int repeat(char av)
{
    int i = 0, j = 0;
    char *s1 = "abcdefghijklmnopqrstupwxyz";
    char *s2 = "ABCDEFGHIJKLMNOPQRSTUPWXYZ";
    if (av >= 'a' && av <= 'z')
    {
        while (s1[j] != '\0')
        {
            if (av == s1[j])
            {
                return j;
                break;
            }
            j++;
        }
    }
    if (av >= 'A' && av <= 'Z')
    {
        while (s1[j] != '\0')
        {
            if (av == s1[j])
            {
                return j;
                break;
            }
            j++;
        }
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 2 || ac < 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    int i = 0, re;
    while (av[1][i] != '\0')
    {
        re = repeat(av[1][i]);
        while (re + 1 > 0)
        {
            write(1, &av[1][i], 1);
            re--;
        }
        i++;
    }
    write(1, "\n", 1);
    return 0;
}