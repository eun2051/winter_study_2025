/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:16:48 by sangjpar          #+#    #+#             */
/*   Updated: 2025/10/04 18:58:16 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
		return (c);
	if (c <= '9' && c >= '0')
		return (c);
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	printf("isalnum = %d\n", ft_isalnum('t'));
}*/
