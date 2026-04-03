/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:10:28 by seungele          #+#    #+#             */
/*   Updated: 2026/01/05 12:38:50 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_connect(char **storage, char *buf, int rd_bytes)
{
	buf[rd_bytes] = '\0';
	*storage = gnl_strjoin(*storage, buf);
	if (!*storage)
		return (0);
	return (1);
}

static int	ft_read(int fd, char **storage)
{
	char		*buf;
	int			bytes;

	if (*storage && gnl_strchr(*storage, '\n'))
		return (1);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1 || (bytes > 0 && !ft_connect(storage, buf, bytes)))
		{
			free(buf);
			return (0);
		}
		if (bytes <= 0 || gnl_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (1);
}

static int	ft_clean_storage(char **storage, size_t line_len)
{
	char	*tmp;
	size_t	rest_len;

	rest_len = gnl_strlen(*storage) - line_len;
	if (rest_len > 0)
	{
		tmp = *storage;
		*storage = gnl_substr(tmp, line_len, rest_len);
		free(tmp);
		if (!*storage)
			return (0);
	}
	else
	{
		free(*storage);
		*storage = NULL;
	}
	return (1);
}

static char	*ft_line(char **storage)
{
	char	*rest_head;
	char	*line;
	size_t	line_len;

	if (!*storage || !**storage)
		return (NULL);
	rest_head = gnl_strchr(*storage, '\n');
	if (rest_head)
		line_len = (rest_head - *storage) + 1;
	else
		line_len = gnl_strlen(*storage);
	line = gnl_substr(*storage, 0, line_len);
	if (!line)
		return (NULL);
	if (!ft_clean_storage(storage, line_len))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_read(fd, &storage[fd]) || !storage[fd] || *storage[fd] == '\0')
	{
		if (storage[fd])
			free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	line = ft_line(&storage[fd]);
	if (!line && storage[fd])
	{
		free(storage[fd]);
		storage[fd] = NULL;
	}
	return (line);
}
