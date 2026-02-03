/* Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str); */

int	ft_strlen(char *str)
{
	int	len;

	while (str[len] != '\0')
		len++;
	return len;
}

char	*ft_strrev(char *str)
{
	int i = 0;
	while (str[i] != '\0') {
		
	}
	return str;
}
