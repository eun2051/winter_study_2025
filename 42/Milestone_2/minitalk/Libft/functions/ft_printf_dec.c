/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 18:00:07 by sangjpar          #+#    #+#             */
/*   Updated: 2025/12/27 16:02:54 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_dec(int print)
{
	int			count;
	long long	num;

	num = (long long)print;
	count = 0;
	if (num < 0)
	{
		num *= -1;
		write(1, "-", 1);
		count = 1;
	}
	putnbr_base(num, "0123456789", &count);
	return (count);
}
