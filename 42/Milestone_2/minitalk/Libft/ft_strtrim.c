/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 12:05:58 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/02 16:09:39 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_set(char const *set, char c)
{
	while (*set != '\0')
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		rindex;
	int		len;
	char	*ret;

	index = 0;
	if (!s1 || !set)
		return (NULL);
	rindex = (int)ft_strlen(s1) - 1;
	while (s1[index] != '\0' && find_set(set, s1[index]))
		index++;
	while (rindex >= index && find_set(set, s1[rindex]))
		rindex--;
	if (index > rindex)
		len = 0;
	else
		len = rindex - index + 1;
	ret = (char *)malloc(len + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1 + index, len);
	ret[len] = '\0';
	return (ret);
}
/*
#include <stdio.h>
int	main()
{
	char s1[] = "lorem \n ipsum \t dolor \n sit \t amet";
	printf("test = %s\n", ft_strtrim(s1, " "));
}*/
