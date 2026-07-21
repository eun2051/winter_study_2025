/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 15:21:57 by seungele          #+#    #+#             */
/*   Updated: 2026/06/28 08:59:09 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main (int ac, char **av)
{
	check_t		c;

	make_philo(&c, ac, av);
	give_num(&c);
	make_fork(&c);
	make_routine(&c);
	check_dead(&c);
	free_all(&c);
	return (0);	
}
