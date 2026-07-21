/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:11:52 by seungele          #+#    #+#             */
/*   Updated: 2026/03/12 17:36:50 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_pop_top(t_stack *s)
{
	int		data;
	t_node	*tmp;
	t_node	*pre;

	check_size(s);
	if (s->size == 1)
	{
		tmp = s->top;
		data = tmp->data;
		free(tmp);
		s->top = NULL;
		s->bottom = NULL;
	}
	else
	{
		tmp = s->top;
		pre = s->top->prev;
		pre->next = NULL;
		s->top = pre;
		data = tmp->data;
		free(tmp);
	}
	s->size--;
	return (data);
}

int	stack_pop_bottom(t_stack *s)
{
	int		data;
	t_node	*tmp;
	t_node	*nex;

	check_size(s);
	if (s->size == 1)
	{
		tmp = s->bottom;
		data = tmp->data;
		free(tmp);
		s->top = NULL;
		s->bottom = NULL;
	}
	else
	{
		tmp = s->bottom;
		nex = s->bottom->next;
		s->bottom = nex;
		nex->prev = NULL;
		data = tmp->data;
		free(tmp);
	}
	s->size--;
	return (data);
}

t_stack	*stack_push_top(t_stack *s, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	if (s->size == 0)
	{
		node->prev = NULL;
		node->next = NULL;
		s->bottom = node;
	}
	else
	{
		s->top->next = node;
		node->prev = s->top;
		node->next = NULL;
	}
	s->top = node;
	s->size++;
	return (s);
}

t_stack	*stack_push_bottom(t_stack *s, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->data = data;
	if (s->size == 0)
	{
		node->prev = NULL;
		node->next = NULL;
		s->top = node;
	}
	else
	{
		s->bottom->prev = node;
		node->next = s->bottom;
		node->prev = NULL;
	}
	s->bottom = node;
	s->size++;
	return (s);
}
