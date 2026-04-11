/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:12:00 by seungele          #+#    #+#             */
/*   Updated: 2026/03/12 16:44:48 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack b;

	if (ac < 2)
		return (0);
	stack_init(&a);
	stack_init(&b);
	parse_num(&a, av);
	check_error(&a);
	push_a2b(&a, &b);
	greedy_sort(&a, &b);
	return (0);
}
