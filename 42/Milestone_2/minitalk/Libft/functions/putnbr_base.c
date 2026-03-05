/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:01:36 by sangjpar          #+#    #+#             */
/*   Updated: 2025/12/27 14:40:42 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_strlen(char *base)
{
	int	size;

	size = 0;
	while (base[size] != '\0')
		size++;
	return (size);
}

void	putnbr_base(long long num, char *base, int *count)
{
	int	size;

	size = ft_strlen(base);
	if (num >= size)
	{
		putnbr_base(num / size, base, count);
		putnbr_base(num % size, base, count);
	}
	else
	{
		write(1, &base[num], 1);
		(*count)++;
	}
}
