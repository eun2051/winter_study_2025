/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:33:46 by seungele          #+#    #+#             */
/*   Updated: 2026/03/18 17:50:28 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_init(t_stack *s)
{
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

void	check_size(t_stack *s)
{
	if (s->size == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	s_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	clear_stack(t_stack *s)
{
	while (s->size > 0)
		stack_pop_top(s);
}
