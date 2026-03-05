/* Write the following functions:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

This function must sort the list given as a parameter, using the function
pointer cmp to select the order to apply, and returns a pointer to the
first element of the sorted list.

Duplications must remain.

Inputs will always be consistent.

You must use the type t_list described in the file list.h
that is provided to you. You must include that file
(#include "list.h"), but you must not turn it in. We will use our own
to compile your assignment.

Functions passed as cmp will always return a value different from
0 if a and b are in the right order, 0 otherwise. */
#include "ft_list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	if (!lst)
		return (NULL);

	t_list	*ptr_1 = lst;
	t_list	*ptr_2 = lst->next;
	int	tmp;

	while (ptr_2)
	{
		if ((*cmp)(ptr_1->data, ptr_2->data) == 0) {
			tmp = ptr_1->data;
			ptr_1->data = ptr_2->data;
			ptr_2->data = tmp;	
			ptr_1 = lst;
			ptr_2 = lst->next;
			continue;
		}
		else {
			ptr_1 = ptr_1->next;
			ptr_2 = ptr_2->next;
		}
	}
	return (lst);
}
