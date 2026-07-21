/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsan.kr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:36:11 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/03 14:54:47 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = new;
	return ;
}
/*
#include <stdio.h>
int	main()
{
	t_list *tmp;
	t_list *a;
	tmp = ft_lstnew("123456");
	a = ft_lstnew("78");
	ft_lstadd_back(&tmp, a);
}
*/
