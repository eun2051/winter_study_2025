/* Write the following function:

int		max(int* tab, unsigned int len);

The first parameter is an array of int, the second is the number of elements in
the array.

The function returns the largest number found in the array.

If the array is empty, the function returns 0. */

#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	if (!tab)
		return 0;
	int i = 0;
	unsigned int max = tab[0];
	while (i < len - 1) {
		if (max < tab[i + 1])
			max = tab[i + 1];
		i++;
	}
	return max;
}

/* int main()
{
	int tab[] = {-10, -5, -20};

	printf("max : %d\n", max(tab, 3));
} */
