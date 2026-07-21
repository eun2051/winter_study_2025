/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 15:49:21 by sangjpar          #+#    #+#             */
/*   Updated: 2025/12/27 16:05:10 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	putnbr_base(long long num, char *base, int *count);
int		ft_printf(const char *str, ...);
int		ft_printf_char(char print);
int		ft_printf_str(char *print);
int		ft_printf_dec(int print);
int		ft_printf_format(const char *str, int *index, va_list args);
int		ft_printf_pointer(void *addr);
int		ft_printf_uint(unsigned int print);
int		ft_printf_hex(unsigned int print, char alpha);
#endif
