/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:35:10 by seungele          #+#    #+#             */
/*   Updated: 2026/04/11 19:35:12 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_push(t_stack *from, t_stack *to, char name)
{
	stack_push_top(to, stack_pop_top(from));
	if (name == 'a')
		write(1, "pa\n", 3);
	else if (name == 'b')
		write(1, "pb\n", 3);
}

void	print_swap(t_stack *s, char name)
{
	int	first;
	int	second;

	first = stack_pop_top(s);
	second = stack_pop_top(s);
	stack_push_top(s, first);
	stack_push_top(s, second);
	if (name == 'a')
		write(1, "sa\n", 3);
	else if (name == 'b')
		write(1, "sb\n", 3);
	else
		return ;
}

void	print_ss(t_stack *a, t_stack *b)
{
	char	n;

	n = '4';
	print_swap(a, n);
	print_swap(b, n);
	write(1, "ss\n", 3);
}
