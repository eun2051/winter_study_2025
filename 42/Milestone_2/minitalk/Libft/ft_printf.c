/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 14:47:45 by sangjpar          #+#    #+#             */
/*   Updated: 2025/12/27 15:12:37 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		index;

	va_start(args, str);
	count = 0;
	index = 0;
	while (str[index])
	{
		count += ft_printf_format(str, &index, args);
		index++;
	}
	va_end(args);
	return (count);
}
/*
int	main()
{
	int size = 0;

	size = ft_printf("In ft_printf: %c\n", '1');
	printf("In printf: %c\n", '1');
	printf("size = %d\n",size);
        size = ft_printf("In ft_printf: %s\n","123456");
	printf("In printf: %s\n", "123456");
	printf("size = %d\n", size);
	size = ft_printf("In ft_printf: %d\n", -123456789);
	printf("In printf: %d\n", -123456789);
	printf("size = %d\n", size);
	size = ft_printf("In ft_printf: %i\n", -123456789);
	printf("In printf: %i\n", -123456789);
	printf("size = %d\n", size);
	size = ft_printf("In ft_printf: %p\n", &size);
	printf("In prinft: %p\n", &size);
	printf("size = %d\n", size);
	size = ft_printf("In ft_printf: %u\n", -2147483647);
	printf("In printf: %u\n", -2147483647);
	printf("size = %d\n", size);
	size = ft_printf("In ft_printf: %x\n", 123456789);
	printf("In printf: %x\n", 123456789);
	printf("size = %d\n", size);
	size = ft_printf("In ft_printf: %X\n", 123456789);
	printf("In printf: %X\n", 123456789);
	printf("size = %d\n", size);

	ft_printf("===========================\n");
	ft_printf("In ft_printf: %p\n", NULL);
	printf("In printf: %p\n", NULL);
	char *test = NULL;
	ft_printf("In ft_printf: %s\n", test);
	printf("In printf: %s\n", test);
}*/
