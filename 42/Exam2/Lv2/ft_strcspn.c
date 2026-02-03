/* Reproduce exactly the behavior of the function strcspn
(man strcspn).

The function should be prototyped as follows:

size_t	ft_strcspn(const char *s, const char *reject); */
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject) {
	size_t	len = 0;
	int	i = 0, j;

	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0') {
			if (s[i] == reject[j]) {
				return len;
			}
			j++;
		}
		len++;
		i++;	
	}
	return len;
}
