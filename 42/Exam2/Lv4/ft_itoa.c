/* Write a function that takes an int and converts it to a null-terminated string.
The function returns the result in a char array that you must allocate.

Your function must be declared as follows:

char	*ft_itoa(int nbr); */
#include <stdlib.h>

int	check_len(long long n)
{
	int len = 1;
	if (n == 0)
		return 1;
	while (n >= 10) {
		n /= 10;
		len++;
	}
	return len;

}


char	*ft_itoa(int nbr)
{
	long long n = nbr;
	int len = check_len(n);
	int sign = 0;
	if (n < 0) {
		sign = 1;
		n = -n;
	}
	char	*str = (char *)malloc(sizeof(char) * (len + sign + 1));
	while (len > 0)
	{
		str[len + sign] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	str[len + sign] = '\0';
	if (sign == 1)
		str[0] = '-';
	return str;
}
