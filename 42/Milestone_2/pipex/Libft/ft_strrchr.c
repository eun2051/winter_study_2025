/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:48:24 by seungele          #+#    #+#             */
/*   Updated: 2025/10/09 13:55:54 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			ptr = s;
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return ((char *)ptr);
}
