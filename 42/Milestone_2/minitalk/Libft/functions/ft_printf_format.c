/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:33:49 by sangjpar          #+#    #+#             */
/*   Updated: 2025/12/27 14:42:59 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_format(const char *str, int *index, va_list args)
{
	int	count;

	count = 0;
	if (str[*index] == '%')
	{
		(*index)++;
		if (str[*index] == 'c')
			count += ft_printf_char((char)va_arg(args, int));
		else if (str[*index] == 's')
			count += ft_printf_str(va_arg(args, char *));
		else if (str[*index] == 'p')
			count += ft_printf_pointer(va_arg(args, void *));
		else if (str[*index] == 'd' || str[*index] == 'i')
			count += ft_printf_dec(va_arg(args, int));
		else if (str[*index] == 'u')
			count += ft_printf_uint(va_arg(args, unsigned int));
		else if (str[*index] == 'x' || str[*index] == 'X')
			count += ft_printf_hex(va_arg(args, unsigned int), str[*index]);
		else if (str[*index] == '%')
			count += write(1, "%", 1);
	}
	else
		count += write(1, &str[*index], 1);
	return (count);
}
