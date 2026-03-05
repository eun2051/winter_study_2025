/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:02:39 by sangjpar          #+#    #+#             */
/*   Updated: 2025/10/05 09:35:57 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s;

	s = ft_strlen(src);
	if (size == 0)
		return (s);
	while (((*src) != '\0') && size - 1 > 0)
	{
		*dst = *src;
		src++;
		dst++;
		size--;
	}
	*dst = '\0';
	return (s);
}
/*
#include <stdio.h>
int	main()
{
	char *a;
	char *b;
	a = malloc(30);
	b = "Hello, World!!123";
	printf("%ld\n", ft_strlcpy(a, b, 20));
	return (0);
}
*/
