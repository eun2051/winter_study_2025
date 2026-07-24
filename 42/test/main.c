/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 08:32:15 by seungele          #+#    #+#             */
/*   Updated: 2026/07/24 15:44:06 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_check	c;
	t_philo *p;

	if (ac != 5 && ac != 6)
		return (1);
	init_check(&c, ac, av);
	p = init_philo(&c);
	if (!p)
		return (1);
	start_threads(p, &c);
	check_dead(p, &c);
	cleanup(p, &c);
	return (0);
}
