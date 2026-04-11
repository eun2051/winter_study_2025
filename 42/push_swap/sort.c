/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:39:40 by seungele          #+#    #+#             */
/*   Updated: 2026/03/18 17:39:42 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	top;
	int	mid;
	int	bot;

	if (is_sorted(a))
		return ;
	top = a->top->data;
	mid = a->top->prev->data;
	bot = a->bottom->data;
	if (top > mid && top > bot && mid > bot)       // [2,1,0] → sa, rra
	{
		print_swap(a, 'a');
		print_rrotate(a, 'a');
	}
	else if (top > mid && top > bot && mid < bot)  // [2,0,1] → ra
		print_rotate(a, 'a');
	else if (top > mid && top < bot)               // [1,0,2] → sa
		print_swap(a, 'a');
	else if (top < mid && top < bot && mid > bot)  // [0,2,1] → rra, sa
	{
		print_rrotate(a, 'a');
		print_swap(a, 'a');
	}
	else                                            // [1,2,0] → rra
		print_rrotate(a, 'a');
}

void	push_a2b(t_stack *a, t_stack *b)
{
	int	*lista;

	lista = stacka_list(a);
	stacka_quick(lista, 0, a->size - 1);
	find_data(a, lista);
	free(lista);
	while (a->size > 3)
		print_push(a, b, 'b');
	if (a->size == 3)
		sort_three(a);
	if (a->size == 2 && !is_sorted(a))
		print_swap(a, 'a');
}