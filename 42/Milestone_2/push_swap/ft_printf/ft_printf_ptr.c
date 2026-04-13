/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:16:55 by seungele          #+#    #+#             */
/*   Updated: 2025/12/26 14:53:30 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long	addr;
	int					len;

	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 0;
	addr = (unsigned long long)ptr;
	len += write(1, "0x", 2);
	len += ft_putnbr_base(addr, "0123456789abcdef");
	return (len);
}

int	ft_putnbr_base(unsigned long long n, char *base)
{
	unsigned long long	base_len;
	int					count;

	count = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
		count += ft_putnbr_base(n / base_len, base);
	count += ft_putchar(base[n % base_len]);
	return (count);
}

// #include <stdio.h>

// int main(void)
// {
//     void *ptr = NULL;

//     printf("Real printf %%p: [%p]\n", ptr);
//     printf("Real printf %%s: [%s]\n", (char *)ptr);
//     return (0);
// }
// 리눅스 환경에서 printf가 null 포인터를 (nil)로 출력하고 있다는 것을 확인