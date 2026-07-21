/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 17:45:41 by sangjpar          #+#    #+#             */
/*   Updated: 2025/12/27 16:03:13 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	putnbr_base_pointer(unsigned long long num, char *base, int *count)
{
	unsigned long long	size;

	size = 16;
	if (num >= size)
	{
		putnbr_base_pointer(num / size, base, count);
		putnbr_base_pointer(num % size, base, count);
	}
	else
	{
		write(1, &base[num], 1);
		(*count)++;
	}
}

int	ft_printf_pointer(void *addr)
{
	unsigned long long	num;
	int					count;

	count = 2;
	num = (unsigned long long)addr;
	if (num == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	putnbr_base_pointer(num, "0123456789abcdef", &count);
	return (count);
}
