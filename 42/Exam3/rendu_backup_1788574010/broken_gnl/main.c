#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return 0;
}
