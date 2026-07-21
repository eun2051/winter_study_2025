/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:40:11 by seungele          #+#    #+#             */
/*   Updated: 2025/10/09 13:56:02 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*tmp;

	tmp = malloc(nelem * elsize);
	if (!tmp)
		return (0);
	ft_memset(tmp, 0, nelem * elsize);
	return (tmp);
}
