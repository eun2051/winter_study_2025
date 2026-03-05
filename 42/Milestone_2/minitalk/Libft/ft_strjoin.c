/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:54:52 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/02 15:43:10 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	char	*ret;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	ret = (char *)malloc(size_s1 + size_s2 + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, size_s1);
	ft_memcpy(ret + size_s1, s2, size_s2);
	ret[size_s1 + size_s2] = '\0';
	return (ret);
}
/*
#include <stdio.h>
int	main()
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
//	char	*strjoin;
	printf("result = %s\n", ft_strjoin(s1, s2));
}*/
