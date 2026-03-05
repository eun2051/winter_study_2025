/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 08:06:10 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/07 21:34:29 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	if ((!dest && !src) || n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*--d = *--s;
	}
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
//	int	a[9] = {1,2,3,4,5, 6};
	char	a[] = "Hello World!";
	char	*b;
//	int	*b;
	b = malloc(36);
	ft_memmove(b, a, 21);
//	while (*b != '\0')
//	{
//		printf("%c", *b);
//		b++;
//	}
//	for (int i = 0 ; i < 9 ; i++)
//		printf("%d\n", b[i]);
	printf("%s\n", b);
}*/
