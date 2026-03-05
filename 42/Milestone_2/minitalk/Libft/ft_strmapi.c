/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:12:04 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/02 20:22:15 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*ret;

	index = 0;
	ret = (char *)malloc(ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	while (s[index] != '\0')
	{
		ret[index] = f(index, s[index]);
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
/*
#include <stdio.h>

char	function(unsigned int a, char b)
{
	return (b);
}

int	main()
{
	char a[] = "12456";
	printf("for test: %s\n", ft_strmapi(a, function));
}*/
