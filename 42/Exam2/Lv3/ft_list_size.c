/* Write a function that returns the number of elements in the linked list that's
passed to it.

It must be declared as follows:

int	ft_list_size(t_list *begin_list); */
#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    int size = 1;
    t_list *ptr = begin_list;
    if (ptr == NULL)
        return 0;
    while (ptr->next != NULL) {
        size++;
        ptr = ptr->next;
    }
    return size;
}