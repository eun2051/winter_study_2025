/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:25:06 by seungele          #+#    #+#             */
/*   Updated: 2026/03/12 17:39:26 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	t_node	*cur;

	if (s->size <= 1)
		return (1);
	cur = s->top;
	while (cur != NULL && cur->prev != NULL)
	{
		if (cur->data > cur->prev->data)
			return (0);
		cur = cur->prev;
	}
	return (1);
}

int	check_dup(t_stack *s)
{
	t_node	*a;
	t_node	*b;

	a = s->top;
	while (a != NULL)
	{
		b = a->prev;
		while (b != NULL)
		{
			if (a->data == b->data)
				return (0);
			b = b->prev;
		}
		a = a->prev;
	}
	return (1);
}

long long	check_overflow(long long a, int next, int sign)
{
	long long	check;

	check = a * 10 + next;
	if (sign == 1 && check > INT_MAX)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (sign == -1 && (check * sign) < INT_MIN)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (check);
}

void	check_error(t_stack *s)
{
	if (check_dup(s) == 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (is_sorted(s) == 1)
		exit(0);
}
