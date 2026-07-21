/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:28:10 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/03 12:19:54 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	num;
	char		a;

	num = (long long)n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num *= -1;
	}
	if (num < 10)
	{
		a = num + '0';
		write(fd, &a, 1);
	}
	if (num > 9)
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putnbr_fd(num % 10, fd);
	}
}
/*
int	main()
{
	ft_putnbr_fd(21, 1);
}*/
