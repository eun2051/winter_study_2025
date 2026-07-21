/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 11:24:15 by sangjpar          #+#    #+#             */
/*   Updated: 2025/10/05 17:31:52 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*src;
	unsigned char		instance;
	size_t				index;

	src = (const unsigned char *)s;
	instance = (unsigned char)c;
	index = 0;
	while (index < n)
	{
		if (src[index] == instance)
			return ((void *)(src + index));
		index++;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main()
{
	const char	*s;
	char	*b;
	s = malloc(30);
	s = "HEllo, WORLd!@#$%^&*()";
	b = ft_memchr(s, 'E', 30);
	printf("%s\n", b);
}*/
