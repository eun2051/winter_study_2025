/* Reproduce exactly the behavior of the strspn function 
(man strspn).

The function should be prototyped as follows:

size_t	ft_strspn(const char *s, const char *accept); */

#include <stdio.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	len = 0;
	int	i = 0, j;

	while (s[i] != '\0') {
		j = 0;
		while (accept[j] != '\0') {
			if (s[i] == accept[j]) {
				len += 1;
				break;
			}
			else if (s[i] != accept[j])
				return len;
			j++;
		}
		i++;
	}
	return len;
}

int main()
{
	printf("%zu\n", ft_strspn("hepy", "world"));
}
