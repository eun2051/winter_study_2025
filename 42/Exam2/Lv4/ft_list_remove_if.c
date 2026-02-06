/* Write a function called ft_list_remove_if that removes from the
passed list any element the data of which is "equal" to the reference data.

It will be declared as follows :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());

cmp takes two void* and returns 0 when both parameters are equal. */
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*curr = *begin_list;
	t_list	*prev = NULL;
	t_list	*remove = NULL;

	if (begin_list == NULL || *begin_list == NULL)
		return ;
	while (curr) {
		if ((*cmp)(curr->data, data_ref) == 0) {
			remove = curr;
			if (prev == NULL)
				*begin_list = curr->next;
			else
				prev->next = curr->next;
			curr = curr->next;
			free(remove);
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
}
