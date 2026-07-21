/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:47:17 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/02 11:54:06 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	size;
	size_t	copy_len;

	size = ft_strlen(s);
	if (start >= size)
	{
		ret = (char *)malloc(1);
		if (ret == NULL)
			return (NULL);
		*ret = '\0';
		return (ret);
	}
	if (len > size - start)
		copy_len = size - start;
	else
		copy_len = len;
	ret = (char *)malloc(copy_len + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s + start, copy_len);
	*(ret + copy_len) = '\0';
	return (ret);
}
/*
#include <stdio.h>
int	main()
{
	char	a[] = "123456789";
	char	str[] = "lorem ipsum dolor sit amet";
	printf("a = %s\n", a);
	printf("test = %s\n", ft_substr(a, 1, 10));
}*/
