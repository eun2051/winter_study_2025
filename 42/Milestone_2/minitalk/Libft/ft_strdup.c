/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 10:31:42 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/02 10:45:36 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*ret;

	size = ft_strlen(s);
	ret = (char *)malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s, size);
	ret[size] = '\0';
	return (ret);
}
