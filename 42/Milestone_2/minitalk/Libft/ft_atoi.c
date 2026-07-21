/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:40:18 by sangjpar          #+#    #+#             */
/*   Updated: 2025/10/05 20:22:52 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	const unsigned char	*str;
	int					result;
	int					sign;

	result = 0;
	sign = 1;
	str = (const unsigned char *)nptr;
	while (*str == '\r' || *str == '\v' || *str == '\f' || *str == '\t'
		|| *str == '\n' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
#include <stdio.h>

int	main()
{
	{
		char a[] = " 123";
		printf("ft_atoi test %s = %d\n", a, ft_atoi(a));
		printf("\n\n\n================================\n\n\n");
	}
        {   
                char a[] = "-123";
                printf("ft_atoi test %s = %d\n", a, ft_atoi(a));
		printf("\n\n\n================================\n\n\n");
        }
		{   
                char a[] = "--123";
                printf("ft_atoi test %s = %d\n", a, ft_atoi(a));
		printf("\n\n\n================================\n\n\n");
        }
		{
                char a[] = "\t123";
                printf("ft_atoi test %s = %d\n", a, ft_atoi(a));
		printf("\n\n\n================================\n\n\n");

        }
        {   
                char a[] = "\v123";
                printf("ft_atoi test %s = %d\n", a, ft_atoi(a));
		printf("\n\n\n================================\n\n\n");
        }
	{
                char a[] = "\f123";
                printf("ft_atoi test %s = %d\n", a, ft_atoi(a));
		printf("\n\n\n================================\n\n\n");
        }
	{
                char a[] = "\n123";
                printf("ft_atoi test %s = %d\n", a, ft_atoi(a));
		printf("\n\n\n================================\n\n\n");
        }
	{
                char a[] = "\r123";
                printf("ft_atoi test %s = %d\n", a, ft_atoi(a));
		printf("\n\n\n================================\n\n\n");
        }
	{
                char a[] = " 123";
                printf("ft_atoi test %s = %d\n", a, ft_atoi(a));
		printf("\n\n\n================================\n\n\n");
        }
	{
                char a[] = "\123";
                printf("ft_atoi test %s = %d\n", a, ft_atoi(a));
		printf("\n\n\n================================\n\n\n");
        }
}
*/