/* Write the following function:

void sort_int_tab(int *tab, unsigned int size);

It must sort (in-place) the 'tab' int array, that contains exactly 'size'
members, in ascending order.

Doubles must be preserved.

Input is always coherent. */
#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	int i, j = 0;
	int tmp;
	while (j < size - 1) {
		i = 0;
		while (i < size - 1 - j) {
			if (tab[i] > tab[i+ 1]) {
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		j++;
	}
}

int main()
{
	int tab[] = {3, 1, 4, 2, 5};
	unsigned int size = 5;
	unsigned int i = 0;

	while (i < size) {
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	sort_int_tab(tab, size);
	i = 0;
	while (i < size) {
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}
