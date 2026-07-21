/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:57:30 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/03 14:54:33 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	tmp = *lst;
	if (tmp == NULL)
		return ;
	next = tmp -> next;
	while (next != NULL)
	{
		del(tmp -> content);
		free(tmp);
		tmp = next;
		next = tmp -> next;
	}
	del(tmp -> content);
	free(tmp);
	*lst = NULL;
}
