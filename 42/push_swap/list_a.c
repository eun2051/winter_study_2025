/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:39:49 by seungele          #+#    #+#             */
/*   Updated: 2026/04/11 19:35:26 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stacka_list(t_stack *a)
{
	int		i;
	int		*lista;
	t_node	*cur;

	lista = (int *)malloc(sizeof(int) * (a->size));
	if (!lista)
		exit(1);
	i = 0;
	cur = a->bottom;
	while (i < a->size)
	{
		lista[i] = cur->data;
		cur = cur->next;
		i++;
	}
	return (lista);
}

int	stacka_median(int *lista, int start, int end)
{
	int	med;

	med = (start + end) / 2;
	if (lista[start] > lista[med])
		s_swap(&lista[start], &lista[med]);
	if (lista[start] > lista[end])
		s_swap(&lista[start], &lista[end]);
	if (lista[med] > lista[end])
		s_swap(&lista[med], &lista[end]);
	s_swap(&lista[med], &lista[end - 1]);
	return (lista[end - 1]);
}

int	stacka_part(int *lista, int start, int end)
{
	int	pivot;
	int	low;
	int	high;

	pivot = stacka_median(lista, start, end);
	low = start;
	high = end - 2;
	while (1)
	{
		while (lista[low] < pivot)
			low++;
		while (lista[high] > pivot)
			high--;
		if (low >= high)
			break ;
		s_swap(&lista[low], &lista[high]);
	}
	s_swap(&lista[low], &lista[end - 1]);
	return (low);
}

void	stacka_quick(int *lista, int start, int end)
{
	int	piv_index;

	if (start + 2 <= end)
	{
		piv_index = stacka_part(lista, start, end);
		stacka_quick(lista, start, piv_index - 1);
		stacka_quick(lista, piv_index + 1, end);
	}
	else
	{
		if (start < end && lista[start] > lista[end])
			s_swap(&lista[start], &lista[end]);
	}
}

int	binary_search(int *lista, int size, int target)
{
	int	low;
	int	high;
	int	mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (lista[mid] == target)
			return (mid);
		else if (lista[mid] < target)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}
