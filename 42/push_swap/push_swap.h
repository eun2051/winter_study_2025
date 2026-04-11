/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:11:23 by seungele          #+#    #+#             */
/*   Updated: 2026/03/18 17:52:26 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				data;
	int				pos;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int				size;
	struct s_node	*top;
	struct s_node	*bottom;
}	t_stack;

int			get_cost(int pos, int size);
int			get_total(t_stack *a, t_stack *b, t_node *cur);
int			is_sorted(t_stack *s);
int			check_dup(t_stack *s);
int			*stacka_list(t_stack *a);
int			stacka_median(int *lista, int start, int end);
int			stacka_part(int	*lista, int start, int end);
int			binary_search(int *lista, int size, int target);
int			stack_pop_top(t_stack *s);
int			stack_pop_bottom(t_stack *s);
t_stack		*stack_push_top(t_stack *s, int data);
t_stack		*stack_push_bottom(t_stack *s, int data);
long long	check_overflow(t_stack *s, long long a, int next, int sign);
void		check_error(t_stack *s);
void		find_data(t_stack *a, int *lista);
void		stacka_quick(int *lista, int start, int end);
void		stack_init(t_stack *s);
void		check_size(t_stack *s);
void		s_swap(int *a, int *b);
void		rotate_dir(t_stack *a, t_stack *b, int *cost_a, int *cost_b);
void		push_mv(t_stack *a, t_stack *b, int cost_a, int cost_b);
void		final_rotate(t_stack *a);
void		greedy_sort(t_stack *a, t_stack *b);
int			ft_abs(int n);
int			get_num(t_stack *s, char *c);
void		parse_num(t_stack *s, char **av);
void		check_parse(char *c);
void		print_rotate(t_stack *s, char name);
void		print_rr(t_stack *a, t_stack *b);
void		print_rrotate(t_stack *s, char name);
void		print_rrr(t_stack *a, t_stack *b);
void		print_push(t_stack *from, t_stack *to, char name);
void		print_swap(t_stack *s, char name);
void		print_ss(t_stack *a, t_stack *b);
void		set_index(t_stack *b);
int			find_target(t_stack *a, int b_data);
int			find_min(t_stack *s);
int			find_max(t_stack *s);
int			find_min_pos(t_stack *s);
void		sort_three(t_stack *a);
void		push_a2b(t_stack *a, t_stack *b);
t_node		*get_total_cost(t_stack *a, t_stack *b);
void		clear_stack(t_stack *s);
void		exit_error(t_stack *a, t_stack *b);

#endif
