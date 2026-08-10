/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungele <seungele@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:32:37 by seungele          #+#    #+#             */
/*   Updated: 2026/02/11 19:48:38 by seungele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	word_cnt_pipex(char const *s, char c)
{
	size_t	count;
	char	quote;

	count = 0;
	quote = 0;
	while (*s)
	{
		while (*s == c && !quote)
			s++;
		if (*s)
			count++;
		while (*s && (*s != c || quote))
		{
			if ((*s == '\'' || *s == '\"') && !quote)
				quote = *s;
			else if (*s == quote)
				quote = 0;
			s++;
		}
	}
	return (count);
}

char	*ft_strndup_pipex(char const *s, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	char	quote;

	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if ((s[i] == '\'' || s[i] == '\"') && !quote)
			quote = s[i++];
		else if (s[i] == quote)
		{
			quote = 0;
			i++;
		}
		else
			str[j++] = s[i++];
	}
	str[j] = '\0';
	return (str);
}

size_t	get_word_len(const char *s, char c)
{
	size_t	len;
	char	quote;

	len = 0;
	quote = 0;
	while (s[len] && (s[len] != c || quote))
	{
		if ((s[len] == '\'' || s[len] == '\"') && !quote)
			quote = s[len];
		else if (s[len] == quote)
			quote = 0;
		len++;
	}
	return (len);
}

int	make_str_pipex(char **result, const char *s, char c)
{
	size_t		i;
	size_t		len;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = get_word_len(s, c);
			result[i] = ft_strndup_pipex(s, len);
			if (!result[i])
			{
				result[i] = NULL;
				free_arr(result);
				return (0);
			}
			s += len;
			i++;
		}
	}
	result[i] = NULL;
	return (1);
}

char	**ft_split_pipex(char const *s, char c)
{
	size_t	len;
	size_t	i;
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (word_cnt_pipex(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			len = get_word_len(s, c);
			result[i++] = ft_strndup_pipex(s, len);
			if (!result[i - 1])
				return (free_arr(result), NULL);
			s += len;
		}
	}
	result[i] = NULL;
	return (result);
}
