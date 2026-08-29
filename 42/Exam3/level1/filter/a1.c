#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 2 || strlen(av[1]) == 0)
		return (1);
	int s_len = strlen(av[1]);
	int acc_len = 0;
	char *acc_buff;
	while (1)
	{
		char tmp_buf[10000];
		int	read_byte = read(0, tmp_buf, sizeof(tmp_buf));
		if (read_byte == -1)
		{
			fprintf(stderr, "Error: read error");
			free(acc_buf);
			return (1);
		}
		if (read_byte == 0)
			break;
		acc_buf = (char *)malloc(sizeof(char) * acc_len + read_byte + 1);
		memmove(acc_buf + acc_len, tmp_buf, read_byte);
		acc_buf[acc_len + read_byte] = '\0';
		acc_len += read_byte;
		while (1)
		{
			char *match = memmem(acc_buf, acc_len, av[1], s_len);
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
				break;
		}
	}
}
