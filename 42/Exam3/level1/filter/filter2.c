#define _GNU_SOURCE
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    char    *acc_buf = NULL;
    char    *base = NULL;
    char    *nb;
    char    tmp[1024];
    size_t  acc_len = 0;
    size_t  s_len;
    ssize_t r;

    if (ac != 2 || !av[1] || av[1][0] == '\0')
        return 1;
    s_len = strlen(av[1]);
    while ((r = read(0, tmp, sizeof(tmp))) > 0)
    {
        nb = realloc(acc_buf, acc_len + r);
        if (!nb)
        {
            free(acc_buf);
            return (1);
        }
        acc_buf = nb;
        memmove(acc_buf + acc_len, tmp, r);
        acc_len += r;
    }
    if (r < 0)
    {
        free(acc_buf);
        return (1);
    }
    while ((base = memmem(acc_buf, acc_len, av[1], s_len)) != NULL)
    {
        size_t i = 0;
        while (i < s_len)
            base[i++] = '*';
    }
    if (acc_len > 0)
        write(1, acc_buf, acc_len);
    free(acc_buf);
    return (0);
}
