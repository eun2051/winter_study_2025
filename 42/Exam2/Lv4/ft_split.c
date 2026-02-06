/* Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str); */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len = 0;

	while (str[len] != '\0')
		len++;
	return len;
}

int	is_space(char *str)
{
	int flag = 0;
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
			i++;
			continue;
		}
		flag++;
		i++;
	}
	return flag;
}

char	**ft_split(char *str)
{
	int	str_len = is_space(str);
	char	**result = (char **)malloc(sizeof(char *) * (str_len + 1));
}
