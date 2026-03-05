/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangjpar <sangjpar@student.42gyeongsa      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 13:03:39 by sangjpar          #+#    #+#             */
/*   Updated: 2025/11/02 16:54:29 by sangjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(char const *s, char c)
{
	int	flag;
	int	count;

	count = 0;
	flag = 1;
	while (*s != '\0')
	{
		if (*s == c)
			flag = 1;
		else if (flag)
		{
			count++;
			flag = 0;
		}
		s++;
	}
	return (count);
}

int	insert(char const *s, char c, char **ret)
{
	int	index;
	int	num;

	index = 0;
	num = 0;
	while (s[index] != c && s[index] != '\0')
		index++;
	*ret = (char *)malloc(sizeof(char) * (index + 1));
	if (*ret == NULL)
		return (-1);
	while (num < index)
	{
		(*ret)[num] = s[num];
		num++;
	}
	(*ret)[num] = '\0';
	while (s[index] == c && s[index] != '\0')
		index++;
	return (index);
}

void	free_all(char **ret, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(ret[i]);
		i++;
	}
	free(ret);
}

char	*skip(char const *s, char c)
{
	char	*result;

	result = (char *)s;
	if (*result == c)
	{
		while (*result == c && *result != '\0')
			result++;
	}
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**ret;
	int		index;
	int		i;

	index = 0;
	i = 0;
	count = word_counter(s, c);
	ret = (char **)malloc(sizeof(char *) * (count + 1));
	if (ret == NULL)
		return (NULL);
	s = skip(s, c);
	while (index < count)
	{
		i = insert(s, c, &(ret[index]));
		s += i;
		if (i == -1)
		{
			free_all(ret, index);
			return (NULL);
		}
		index++;
	}
	ret[count] = NULL;
	return (ret);
}
/*
#include <stdio.h>

int	main(void)
{
	char **r = ft_split("   lorem   ipsum dolor     sit amet, consectetur   
	adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	for (int i = 0; i < 12 ; i++)
		printf("split result = %s\n", r[i]);
}*/
