/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 15:06:17 by sangjpar          #+#    #+#             */
/*   Updated: 2025/10/04 19:40:12 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*result;

	result = (unsigned char *)s;
	while (n > 0)
	{
		(*result) = (unsigned char)c;
		result++;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>

int	main()
{
	char *a;
	a=malloc(36);
	a=ft_memset(a, -65, 30);
	printf("%s", a);
}*/
