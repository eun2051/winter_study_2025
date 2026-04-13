/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:02:13 by seungele          #+#    #+#             */
/*   Updated: 2025/12/21 18:13:53 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
	return (len);
}

int	ft_putnbr(int nb)
{
	long long	n;
	int			result;

	n = nb;
	result = 0;
	if (n < 0)
	{
		result += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		result += ft_putnbr(n / 10);
	result += ft_putchar((n % 10) + '0');
	return (result);
}

int	ft_putuint(unsigned int n)
{
	int	result;

	result = 0;
	if (n >= 10)
		result += ft_putuint(n / 10);
	result += ft_putchar((n % 10) + '0');
	return (result);
}
