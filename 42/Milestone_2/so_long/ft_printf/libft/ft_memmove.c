/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 19:54:31 by seungele          #+#    #+#             */
/*   Updated: 2025/11/02 12:50:22 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dst1;
	const unsigned char	*src1;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	dst1 = (unsigned char *)dest;
	src1 = (const unsigned char *)src;
	if (dst1 < src1)
	{
		while (n--)
			*dst1++ = *src1++;
	}
	else
	{
		dst1 += n;
		src1 += n;
		while (n--)
			*--dst1 = *--src1;
	}
	return (dest);
}
