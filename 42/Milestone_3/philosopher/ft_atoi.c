/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 10:24:50 by seungele          #+#    #+#             */
/*   Updated: 2026/06/27 19:21:48 by seungele         ###   ########.fr       */
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
		if (a > INT_MIN % 10 || (a == INT_MIN / 10 && next >7))
			exit(1);
	}
	return (a * 10 + next);
}
