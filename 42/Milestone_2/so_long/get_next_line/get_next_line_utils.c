/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:11:06 by seungele          #+#    #+#             */
/*   Updated: 2025/12/26 16:21:40 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = 0;
	if (s1)
		s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	str = (char *)malloc(s1_len + s2_len + 1);
	if (!str)
	{
		free(s1);
		return (NULL);
	}
	if (s1)
		gnl_memcpy(str, s1, s1_len);
	gnl_memcpy(str + s1_len, s2, s2_len);
	str[s1_len + s2_len] = '\0';
	free(s1);
	return (str);
}

void	*gnl_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	dst1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	while (n > 0)
	{
		*dst1 = *src1;
		dst1++;
		src1++;
		n--;
	}
	return (dest);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	sub_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = gnl_strlen(s);
	if (s_len <= start)
		return (NULL);
	if (s_len - start < len)
		sub_len = s_len - start;
	else
		sub_len = len;
	sub = (char *)malloc(sub_len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < sub_len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[sub_len] = '\0';
	return (sub);
}
