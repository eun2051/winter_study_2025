/* Write a function that takes a string, splits it into words, and returns them as
a NULL-terminated array of strings.

A "word" is defined as a part of a string delimited either by spaces/tabs/new
lines, or by the start/end of the string.

Your function must be declared as follows:

char    **ft_split(char *str); */
#include <stdlib.h>

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	count_words(char *str)
{
	int count = 0;
	int i = 0;

	while (*str) {
		while (*str && is_space(*str))
			str++;
		if (*str && !is_space(*str)) {
			count++;
			while (*str && !is_space(*str))
				str++;
		}
	}
	return count;
}

char	*make_str(char *str)
{
	int i = 0;

	while (str[i] != '\0' && !is_space(str[i]))
		i++;
	char *new = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !is_space(str[i]))
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return new;
}

char	**ft_split(char *str)
{
	int	words = count_words(str);
	char	**result = (char **)malloc(sizeof(char *) * (words + 1));
	int i = 0;
	while (*str) {
		while (*str && is_space(*str))
			str++;
		if (*str && !is_space(*str))
		{
			result[i] = make_str(str);
			i++;
			while (*str && !is_space(*str))
				str++;
		}
	}
	result[i] = NULL;
	return (result);
}
