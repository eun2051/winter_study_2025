/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:33:25 by sangjpar          #+#    #+#             */
/*   Updated: 2025/12/27 14:45:33 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_hex(unsigned int print, char alpha)
{
	int		count;

	count = 0;
	if (alpha == 'x')
		putnbr_base(print, "0123456789abcdef", &count);
	else
		putnbr_base(print, "0123456789ABCDEF", &count);
	return (count);
}
