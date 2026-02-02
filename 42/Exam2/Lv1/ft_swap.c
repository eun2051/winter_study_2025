/* Write a function that swaps the contents of two integers the adresses of which
are passed as parameters.
Your function must be declared as follows:
void	ft_swap(int *a, int *b); */
#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *A, int *B)
{
    int tmp = *A;
    *A = *B;
    *B = tmp;
}

int main()
{
    int a = 5;
    int b = 3;
    printf("%d %d\n", a, b);
    ft_swap(&a, &b);
    printf("%d %d\n", a, b);
}