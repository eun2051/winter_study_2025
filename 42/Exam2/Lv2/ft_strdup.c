/* Reproduce the behavior of the function strdup (man strdup).

Your function must be declared as follows:

char    *ft_strdup(char *src); */
#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while(str[len] != '\0')
		len++;
	return len;
}

char	*ft_strdup(char *src)
{
	int i = 0;
	int len = ft_strlen(src);
	char	*new = (char *)malloc(len + 1);
	while (src[i] != '\0') {
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return new;
}
