/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:28:19 by sangjpar          #+#    #+#             */
/*   Updated: 2025/10/05 21:27:16 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	num;
	int		index;

	num = 0;
	if (*little == '\0')
		return ((char *)big);
	while ((*big != '\0') && (num < len))
	{
		if (*big == *little)
		{
			index = -1;
			while (little[++index] != '\0')
			{
				if (index + num >= len)
					return (NULL);
				if (big[index] != little[index])
					break ;
			}
			if (little[index] == '\0')
				return ((char *)big);
		}
		num++;
		big++;
	}
	return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	{
		char a[] = "Hello, World@!@#";
		char b[] = ", ";
		printf("result = %s\n", ft_strnstr(a, b, 10));
	}
}*/
