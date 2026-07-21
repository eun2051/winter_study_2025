/* Write the following function:

int     *ft_rrange(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at end and end at start (Including start and end !), then
return a pointer to the first value of the array. */
#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int len = 0;
    if (start <= end)
        len = (end - start) + 1;
    else if (start > end)
        len = (start - end) + 1;
    int *str = (int *)malloc(sizeof(int) * (len));
    int i = 0;
    while (i < len)
    {
        str[i] = end;
        if (end > start)
            end--;
        else if (end < start)
            end++;
        i++;
    }
    return str;
}