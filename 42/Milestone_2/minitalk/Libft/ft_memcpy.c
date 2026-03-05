/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:50:38 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/07 21:23:40 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!d && !s)
		return (dest);
	if (n == 0)
		return (dest);
	while (n > 0)
	{
		(*d) = (*s);
		d++;
		s++;
		n--;
	}
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main()
{
	char a[] = "Hello, World!!123";
	char	*b;
	b = malloc(30);
	b = ft_memcpy(b, a, 20);
	printf("%s\n", b);
}*/
