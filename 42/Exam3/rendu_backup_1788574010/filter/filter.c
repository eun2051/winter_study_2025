#define _GNU_SOURCE
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char *append_buf(char *acc_buf, int *acc_len, char *tmp, int read_byte)
{
	acc_buf = (char *)realloc(acc_buf, *acc_len + read_byte + 1);
	memmove(acc_buf + *acc_len, tmp, read_byte);
	acc_buf[*acc_len + read_byte] = '\0';
	*acc_len += read_byte;
	return (acc_buf);
}

int	process(char *acc_buf, int acc_len, char *s, int s_len)
{
	while (1)
	{
		char *match = memmem(acc_buf, acc_len, s, s_len);
		if (match != NULL)
		{
			write(1, acc_buf, match - acc_buf);
			int i = 0;
			while (i < s_len)
			{
				write(1, "*", 1);
				i++;
			}
			acc_len -= (match - acc_buf) + s_len;
			memmove(acc_buf, match + s_len, acc_len);
		}
		else
		{
			int safe_len = acc_len - (s_len - 1);
			if (safe_len > 0)
			{
				write(1, acc_buf, safe_len);
				memmove(acc_buf, acc_buf + safe_len, s_len - 1);
				acc_len = s_len -1;
			}
			break;
		}
	}
	return (acc_len);
}

int main(int ac, char **av)
{
	if (ac != 2 || strlen(av[1]) == 0)
		return 1;
	int s_len = strlen(av[1]);
	int acc_len = 0;
	char *acc_buf = NULL;
	int read_byte = 0;

	while (1)
	{
		char tmp[1000];
		read_byte = read(0, tmp, 1000);
		if (read_byte == 0)
			break;
		if (read_byte == -1)
		{
			free(acc_buf);
			return 1;
		}
		acc_buf = append_buf(acc_buf, &acc_len, tmp, read_byte);
		acc_len = process(acc_buf, acc_len, av[1], s_len);
	}
	if (acc_len > 0)
		write(1, acc_buf, acc_len);
	free(acc_buf);
	return 0;
}
