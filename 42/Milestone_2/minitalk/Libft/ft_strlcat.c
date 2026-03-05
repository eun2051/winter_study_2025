/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:11:13 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/02 18:12:20 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	d;
	size_t	s;

	index = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (d > size)
		return (size + s);
	while ((*src != '\0') && (d + index + 1 < size))
	{
		*(dst + d + index) = *src++;
		index++;
	}
	*(dst + d + index) = '\0';
	return (d + s);
}
/*
#include <stdio.h>
int	main()
{
	char dest[10] = "a";
	printf("result = %ld\n", ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
	printf("%s\n", dest);
}*/
