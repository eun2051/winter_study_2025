#include "ft_printf.h"

int pntr_write(void);

int main()
{
	int s;

    pntr_write();
	s = ft_printf("%s\n",NULL);
	ft_printf("%d",s, 1,2,3,4,8,6,4,5);
	ft_printf("%c%d%i%x%X\n",s, 1,2,3,4,8,6,4,5);
	ft_printf("Hello %a World");
	return (0);
}

int    pntr_write(void) {
    void    *ptr = NULL;

    printf("Real printf %%p: [%p]\n", ptr);
    printf("Real printf %%s: [%s]\n", (char *)ptr);
    return (0);
}

//cc main.c libftprint.a
//./a.out