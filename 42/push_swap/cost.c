/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:35:41 by seungele          #+#    #+#             */
/*   Updated: 2026/04/11 19:35:42 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost(int pos, int size)
{
	if (pos <= (size / 2))
		return (pos);
	else
		return (-1 * (size - pos));
}

int	get_total(t_stack *a, t_stack *b, t_node *cur)
{
	int	cost_a;
	int	cost_b;
	int	target;
	int	min_total;

	target = find_target(a, cur->data);
	cost_b = get_cost(cur->pos, b->size);
	cost_a = get_cost(target, a->size);
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	if (cost_a < 0 && cost_b < 0)
	{
		if (ft_abs(cost_a) > ft_abs(cost_b))
			return (ft_abs(cost_a));
		return (ft_abs(cost_b));
	}
	min_total = ft_abs(cost_a) + ft_abs(cost_b);
	return (min_total);
}

t_node	*get_total_cost(t_stack *a, t_stack *b)
{
	int		min;
	int		tmp;
	t_node	*best;
	t_node	*cur;

	cur = b->top;
	best = cur;
	min = get_total(a, b, cur);
	while (cur != NULL)
	{
		tmp = get_total(a, b, cur);
		if (tmp < min)
		{
			min = tmp;
			best = cur;
		}
		cur = cur->prev;
	}
	return (best);
}
