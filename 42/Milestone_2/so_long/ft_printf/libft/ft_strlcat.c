/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 16:43:48 by seungele          #+#    #+#             */
/*   Updated: 2025/11/03 18:19:04 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (dst_len >= size)
		return (size + src_len);
	while (src[i] && dst_len + i + 1 < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int main(void)
{
	char	*src = "456789";
	
	char	dest[30] = "123";
	size_t	ret = ft_strlcat(dest, src, 20);
	printf("dest = %s\nreturn = %zu\n", dest, ret);

	//size가 src+dest 이하라면?
	char	dest2[30] = "123";
	size_t	ret2 = ft_strlcat(dest2, src, 7);
	printf("dest = %s\nreturn = %zu\n", dest, ret);

	//size가 dest보다 작다면?
	char	dest3[30] = "123";
	size_t	ret3 = ft_strlcat(dest3, src, 3);
	printf("dest = %s\nreturn = %zu\n", dest, ret);
} */
