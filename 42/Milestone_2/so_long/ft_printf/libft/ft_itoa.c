/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:14:30 by seungele          #+#    #+#             */
/*   Updated: 2025/11/03 18:21:19 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_len(long long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb != 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_zero(char	*result)
{
	result[0] = '0';
	return (result);
}

char	*ft_itoa(int n)
{
	size_t		len;
	long long	nb;
	char		*result;

	nb = (long long)n;
	len = check_len(nb);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (nb == 0)
		return (ft_zero(result));
	if (nb < 0)
	{
		result[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		len--;
		result[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (result);
}
