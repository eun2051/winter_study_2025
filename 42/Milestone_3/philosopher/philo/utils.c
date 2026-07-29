/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:24:50 by seungele          #+#    #+#             */
/*   Updated: 2026/07/29 17:17:27 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_atoi(char *c)
{
	int			sign;
	long long	value;

	sign = 1;
	value = 0;
	while ((*c >= '\t' && *c <= '\r') || *c == ' ')
		c++;
	if (*c == '+' || *c == '-')
	{
		if (*c == '-')
			sign = -1;
		c++;
	}
	check_num(c);
	while (*c >= '0' && *c <= '9')
	{
		value = check_overflow(value, *c - '0', sign);
		c++;
	}
	return (value * sign);
}

void	check_num(char *c)
{
	if (*c < '0' || *c > '9')
		exit(1);
}

long long	check_overflow(long long a, int next, int sign)
{
	if (sign == 1)
	{
		if (a > INT_MAX / 10 || (a == INT_MAX / 10 && next > 7))
			exit(1);
	}
	else if (sign == -1)
	{
		if (a > INT_MIN % 10 || (a == INT_MIN / 10 && next > 7))
			exit(1);
	}
	return (a * 10 + next);
}

void	ft_putnbr_fd(long long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
