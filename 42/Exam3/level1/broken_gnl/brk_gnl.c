#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dst1;
	unsigned char	*src1;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	dst1 = (unsigned char *)dest;
	src1 = (unsigned char *)src;
	while (n > 0)
	{
		*dst1 = *src1;
		dst1++;
		src1++;
		n--;
	}
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	len = 0;

	if (!s)
		return (0);
	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t size1 = ft_strlen(*s1);
	char *tmp = (char *)malloc(size2 + size1 + 1);
	if (!tmp)
		return 0;
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return str_append_mem(s1, s2, ft_strlen(s2));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dst1;
	const unsigned char *src1;

	if (n == 0)
		return (dest);
	if (!dest && !src)
		return (NULL);
	dst1 = (unsigned char *)dest;
	src1 = (const unsigned char *)src;
	if (dst1 < src1)
	{
		while (n--)
			*dst1++ = *src1++;
	} else {
		dst1 += n;
		src1 += n;
		while (n--)
			*--dst1 = *--src1;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	static char b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;
	char	*tmp = ft_strchr(b, '\n');
	int	read_ret = 0;

	// 보호 구문 (안전을 위해 추가)
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		read_ret = read(fd, b, BUFFER_SIZE);
		
		if (read_ret == 0)
		{
			b[0] = '\0';
			break;
		}
		if (read_ret == -1)
		{
			free(ret);
			b[0] = '\0';
			return (NULL);
		}
		b[read_ret] = '\0';
		tmp = ft_strchr(b, '\n');
	}
	if (tmp)
	{
		if (!str_append_mem(&ret, b, tmp - b + 1))
		{
			free(ret);
			return (NULL);
		}
		ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	} else
	{
		if (!ret || *ret == '\0')
		{
			free(ret);
			ret = NULL;
		}
	}
	return (ret);
}