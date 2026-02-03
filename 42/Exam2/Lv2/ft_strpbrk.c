/* Reproduce exactly the behavior of the function strpbrk
(man strpbrk).

The function should be prototyped as follows:

char	*ft_strpbrk(const char *s1, const char *s2); */

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i = 0, j;
	char	*s = (char *)s1;
	char 	*accept = (char *)s2;

	if (!s1 || !s2)
		return NULL;
	while (s[i] != '\0') {
		j = 0;
		while (accept[j] != '\0') {
			if (s[i] == accept[j])
				return (&s[i]);
			j++;
		}
		i++;
	}
	return NULL;
}

/* int main()
{
	const char *str1 = "abc";
	const char *str2 = "xyz";
	char *result;

	result = ft_strpbrk(str1, str2);
	if (result != NULL)
		printf("%c\n", *result);
	else
		printf("NULL");
} */
