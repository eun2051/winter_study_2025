/* Write a function that converts the string argument str (base N <= 16)
to an integer (base 10) and returns it.

The characters recognized in the input are: 0123456789abcdef
Those are, of course, to be trimmed according to the requested base. For
example, base 4 recognizes "0123" and base 16 recognizes "0123456789abcdef".

Uppercase letters must also be recognized: "12fdb3" is the same as "12FDB3".

Minus signs ('-') are interpreted only if they are the first character of the
string.

Your function must be declared as follows:

int	ft_atoi_base(const char *str, int str_base); */

int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	sign = 1;
	int	result = 0;

	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9') {
			result *= str_base;
			result += str[i] - '0';
			i++;
		}
		else if (str[i] >= 'a' && str[i] <= 'z') {
			result *= str_base;
			result += str[i] - 'a' + 10;
			i++;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			result *= str_base;
			result += str[i] - 'A' + 10;
			i++;
		}
	}
	return (sign * result);
}
