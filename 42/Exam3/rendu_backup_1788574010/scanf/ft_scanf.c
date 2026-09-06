#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	int c;
	while (1)
	{
		c = fgetc(f);
		if (c == EOF || isspace(c) == 0)
		{
			ungetc(c, f);
			break;
		}
	}
    	return (0);
}

int match_char(FILE *f, char c)
{
	int m_c = fgetc(f);
	if (m_c == c)
		return 1;
	else
	{
		ungetc(m_c, f);
		return 0;
	}
}

int scan_char(FILE *f, va_list ap)
{
	char *ptr;
	int c = fgetc(f);

	if (c == EOF)
		return 0;
	ptr = va_arg(ap, char *);
        *ptr = c;
    	return (1);
}

int scan_int(FILE *f, va_list ap)
{
	int *ptr = va_arg(ap, int *);
	int c = fgetc(f);
	int res = 0;
	int cnt = 0;
	int sign = 1;
	
	if (c == '-')
		sign = -1;
	else if (c == '+')
		sign = 1;
	else
		ungetc(c, f);
	while (1)
	{
		c = fgetc(f);
		if (!isdigit(c))
		{
			ungetc(c, f);
			break;
		}
		res = res * 10 + c - '0';
		cnt++;
	}
	if (cnt > 0)
	{
		*ptr = res * sign;
		return 1;
	}
	else
		return 0;
}

int scan_string(FILE *f, va_list ap)
{
	char *str = va_arg(ap, char *);
	int i = 0;

	while (1)
	{
		int c = fgetc(f);
		if (c == EOF || isspace(c) != 0)
		{
			ungetc(c, f);
			break;
		}
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	if (i > 0)
		return 1;
	else
		return 0;
    return (0);
}


int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}


int ft_scanf(const char *format, ...)
{
	va_list ap;
	va_start(ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}

