/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:13:22 by seungele          #+#    #+#             */
/*   Updated: 2026/03/12 17:24:26 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_num(t_stack *s, char *c)
{
	int			sign;
	long long	value;

	sign = 1;
	value = 0;
	while ((*c >= '\t' && *c <= '\r') || *c == ' ')
		c++;
	if (*c == '+' || *c == '-')
	{
		if (*c == '-')
			sign = -1;
		c++;
	}
	check_parse(s, c);
	while (*c >= '0' && *c <= '9')
	{
		value = check_overflow(s, value, *c - '0', sign);
		c++;
	}
	return (value * sign);
}

void	parse_num(t_stack *s, char **av)
{
	int		i;
	int		data;
	char	*curr;

	i = 1;
	while (av[i] != NULL)
	{
		curr = av[i];
		while (*curr != '\0')
		{
			while (*curr == ' ' || (*curr >= '\t' && *curr <= '\r'))
				curr++;
			if (*curr == '\0')
				break ;
			data = get_num(s, curr);
			stack_push_bottom(s, data);
			if (*curr == '+' || *curr == '-')
				curr++;
			while (*curr >= '0' && *curr <= '9')
				curr++;
		}
		i++;
	}
	check_error(s);
}

void	check_parse(t_stack *s, char *c)
{
	if (*c < '0' || *c > '9')
		exit_error(s, NULL);
}
