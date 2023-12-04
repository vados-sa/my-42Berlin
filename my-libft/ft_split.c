/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:45 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/04 08:56:38 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c);
static size_t	fill_words(char **array, char const *s, char c);
static size_t	safe_alloc_mem(char **array, size_t pos, size_t size);

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		else
		{
			while (*s == c && *s)
				s++;
		}
	}
	return (count);
}

static size_t	fill_words(char **array, char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (safe_alloc_mem(array, i, len + 1))
				return (1);
			ft_strlcpy(array[i], s - len, len + 1);
		}
		i++;
	}
	return (0);
}

static size_t	safe_alloc_mem(char **array, size_t pos, size_t size)
{
	size_t	i;

	i = 0;
	array[pos] = malloc(size);
	if (!array[pos])
	{
		while (i < pos)
			free (array[i++]);
		free (array);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	size_t			words;
	char			**array;

	words = 0;
	words = count_words(s, c);
	array = (char **)malloc((words + 1) * sizeof(char *));
	if (!array || !s)
		return (NULL);
	if (fill_words(array, s, c))
		return (NULL);
	array[words] = NULL;
	return (array);
}
