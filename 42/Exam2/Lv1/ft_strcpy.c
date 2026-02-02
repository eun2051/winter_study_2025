/* Reproduce the behavior of the function strcpy (man strcpy).
Your function must be declared as follows:
char    *ft_strcpy(char *s1, char *s2); */
#include <unistd.h>
#include <stdio.h>

int     ft_strlen(char *str)
{
    int i = 0;
    int cnt = 0;
    while (str[i] != '\0') {
        i++;
        cnt++;
    }
    return (cnt);
}

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    int s1_len = ft_strlen(s1);
    int s2_len = ft_strlen(s2);
    printf("s1 len : %d | s2 len : %d\n", s1_len, s2_len);
    while (i < s2_len) {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

int main()
{
    char s1[] = "hello";
    char s2[] = "program";

    printf("%s %s\n", s1, s2);
    ft_strcpy(s1, s2);
    printf("%s %s\n", s1, s2);
}