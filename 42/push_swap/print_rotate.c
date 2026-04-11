/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:13:36 by seungele          #+#    #+#             */
/*   Updated: 2026/03/12 16:13:37 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_rotate(t_stack *s, char name)
{
	stack_push_bottom(s, stack_pop_top(s));
	if (name == 'a')
		write(1, "ra\n", 3);
	else if (name == 'b')
		write(1, "rb\n", 3);
}

void	print_rr(t_stack *a, t_stack *b)
{
	stack_push_bottom(a, stack_pop_top(a));
	stack_push_bottom(b, stack_pop_top(b));
	write(1, "rr\n", 3);
}

void	print_rrotate(t_stack *s, char name)
{
	stack_push_top(s, stack_pop_bottom(s));
	if (name == 'a')
		write(1, "rra\n", 4);
	else if (name == 'b')
		write(1, "rrb\n", 4);
}

void	print_rrr(t_stack *a, t_stack *b)
{
	stack_push_top(a, stack_pop_bottom(a));
	stack_push_top(b, stack_pop_bottom(b));
	write(1, "rrr\n", 4);
}
