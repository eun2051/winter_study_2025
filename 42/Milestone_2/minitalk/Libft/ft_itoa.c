/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 09:53:42 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/03 11:39:13 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cal_len(long long *num, int *sign)
{
	int			count;
	long long	tmp;

	count = 1;
	*sign = 0;
	if (*num < 0)
	{
		count++;
		*num *= -1;
		*sign = 1;
	}
	tmp = *num;
	while (tmp > 9)
	{
		tmp /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			size;
	char		*result;
	int			sign;
	int			index;

	index = 0;
	num = (long long)n;
	size = cal_len(&num, &sign);
	result = (char *)malloc(size + 1);
	if (result == NULL)
		return (NULL);
	if (sign)
		result[index] = '-';
	while (num > 9)
	{
		result[size - 1 - index] = (num % 10) + '0';
		num /= 10;
		index++;
	}
	if (num < 10)
		result[size - 1 - index] = num + '0';
	result[size] = '\0';
	return (result);
}
/*
#include <stdio.h>
int	main()
{
	int	n = 2;
	printf("%d -> %s\n", n, ft_itoa(n));
}*/
