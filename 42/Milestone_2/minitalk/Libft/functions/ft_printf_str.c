/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 16:23:15 by sangjpar          #+#    #+#             */
/*   Updated: 2025/12/27 15:07:18 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_str(char *print)
{
	int	index;

	index = 0;
	if (print == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (print[index])
		write(1, &print[index++], 1);
	return (index);
}
