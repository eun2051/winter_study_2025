/* Write a function that returns the length of a string.
Your function must be declared as follows:
int	ft_strlen(char *str); */
#include <unistd.h>

int ft_strlen(char *str)
{
    int i = 0;
    int cnt = 0;
    while (str[i] != '\0') {
        i++;
        cnt++;
    }
    return (cnt);
}