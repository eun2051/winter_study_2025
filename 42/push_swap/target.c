/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:35:04 by seungele          #+#    #+#             */
/*   Updated: 2026/04/11 19:35:06 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *b)
{
	int		i;
	t_node	*cur;

	i = 0;
	cur = b->top;
	while (cur != NULL)
	{
		cur->pos = i;
		i++;
		cur = cur->prev;
	}
}

int	find_target(t_stack *a, int b_data)
{
	int		result;
	t_node	*cur;
	t_node	*target;

	if (b_data > find_max(a) || b_data < find_min(a))
		result = find_min_pos(a);
	else
	{
		cur = a->top;
		target = NULL;
		while (cur != NULL)
		{
			if (cur->data > b_data)
			{
				if (target == NULL || cur->data < target->data)
					target = cur;
			}
			cur = cur->prev;
		}
		if (!target)
			result = find_min_pos(a);
		else
			result = target->pos;
	}
	return (result);
}

int	find_min(t_stack *s)
{
	int		min_d;
	t_node	*cur;

	cur = s->top;
	min_d = cur->data;
	while (cur != NULL)
	{
		if (cur->data < min_d)
			min_d = cur->data;
		cur = cur->prev;
	}
	return (min_d);
}

int	find_min_pos(t_stack *s)
{
	int		min_d;
	int		min_p;
	t_node	*cur;

	cur = s->top;
	min_d = cur->data;
	min_p = cur->pos;
	while (cur != NULL)
	{
		if (cur->data < min_d)
		{
			min_d = cur->data;
			min_p = cur->pos;
		}
		cur = cur->prev;
	}
	return (min_p);
}

int	find_max(t_stack *s)
{
	int		max_d;
	t_node	*cur;

	cur = s->top;
	max_d = cur->data;
	while (cur != NULL)
	{
		if (cur->data > max_d)
			max_d = cur->data;
		cur = cur->prev;
	}
	return (max_d);
}
