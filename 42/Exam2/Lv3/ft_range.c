/* Write the following function:

int     *ft_range(int start, int end);

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array. */
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int len = 0;
	if (start <= end)
		len = (end - start) + 1;
	else if (start > end)
		len = (start - end) + 1;
	int *str = (int *)malloc((len) * sizeof(int));
	int i = 0;
	while (i < len) {
		str[i] = start;
		if (start < end)
			start++;
		else if (start > end)
			start--;
		i++;
	}
	return str;
}