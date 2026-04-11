#include "push_swap.h"

void    rotate_dir(t_stack *a, t_stack *b, int *cost_a, int *cost_b)
{
    if (*cost_a > 0 && *cost_b > 0)
    {
        while (*cost_a > 0 && *cost_b > 0)
        {
            print_rr(a, b);
            (*cost_a)--;
            (*cost_b)--;
        }
    }
    else if (*cost_a < 0 && *cost_b < 0)
    {
        while (*cost_a < 0 && *cost_b < 0)
        {
            print_rrr(a, b);
            (*cost_a)++;
            (*cost_b)++;
        }
    }

}

void    push_mv(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
    rotate_dir(a, b, &cost_a, &cost_b);
    while (cost_a > 0)
    {
        print_rotate(a, 'a');
        cost_a--;
    }
    while (cost_a < 0)
    {
        print_rrotate(a, 'a');
        cost_a++;
    }
    while (cost_b > 0)
    {
        print_rotate(b, 'b');
        cost_b--;
    }
    while (cost_b < 0)
    {
        print_rrotate(b, 'b');
        cost_b++;
    }
    print_push(b, a, 'a');
}

void    final_rotate(t_stack *a)
{
    int min_pos;
    int cost;

    set_index(a);
    min_pos = find_min_pos(a);
    cost = get_cost(min_pos, a->size);
    while (cost != 0)
    {
        if (cost > 0)
        {
            print_rotate(a, 'a');
            cost--;
        }
        else
        {
            print_rrotate(a, 'a');
            cost++;
        }
    }
}

void	greedy_sort(t_stack *a, t_stack *b)
{
	int		target;
	int		cost_a;
	int		cost_b;
	t_node	*best;

	while (b->size > 0)
	{
		set_index(a);
		set_index(b);
		best = get_total_cost(a, b);
		target = find_target(a, best->data);
		cost_b = get_cost(best->pos, b->size);
		cost_a = get_cost(target, a->size);
		push_mv(a, b, cost_a, cost_b);
	}
	final_rotate(a);
}