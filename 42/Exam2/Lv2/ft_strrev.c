/* Write a function that reverses (in-place) a string.

It must return its parameter.

Your function must be declared as follows:

char    *ft_strrev(char *str); */

int	ft_strlen(char *str)
{
	int	len;
	
	len = 0;
	while (str[len] != '\0')
		len++;
	return len;
}

char	*ft_strrev(char *str)
{
	int i = 0;
	int end = ft_strlen(str) - 1;
	while (i < end) {
		int tmp = str[i];
		str[i] = str[end];
		str[end] = tmp;
		i++;
		end--;
	}
	return str;
}

/*
int main()
{
	char str[] = "werlskdjflskdjflskdjf";
	printf("%s\n", ft_strrev(str));
} */
