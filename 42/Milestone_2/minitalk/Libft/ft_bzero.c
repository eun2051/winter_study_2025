/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:33:55 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/02 09:19:56 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
	return ;
}
/*
#include <stdlib.h>
#include <stdio.h>

int	main()
{
	char *a;
	a = malloc(10);
	printf("%s\n", a);
	ft_bzero(a, 0);
	printf("%s\n", a);
	return (0);
}*/
