/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:45 by vados-sa          #+#    #+#             */
/*   Updated: 2024/02/20 15:14:19 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_split(char const *s, char c);
static int	count_words(char const *s, char c);
static char		*fill_words(char const *s, char c);

static int	count_words(char const *s, char c)
{
	int	count;

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

/*This function gets the next argument from av.*/
static char	*fill_words(char const *s, char c)
{
	static int	cursor;	
	char		*arg_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == c)
		cursor++;
	while (s[cursor + len] != c && s[cursor + len])
		len++;
	arg_str = malloc(len * sizeof(char) + 1);
	if (!arg_str)
		return (NULL);
	while (s[cursor] != c && s[cursor])
		arg_str[i++] = s[cursor++]; 
	arg_str[i] = '\0';
	return (arg_str);
}

char	**ft_split(char const *s, char c)
{
	int			words;
	char		**array;
	int			i;

	i = 0;
	words = count_words(s, c);
	if(!words)
		exit(1);
	array = malloc((words + 2) * sizeof(char *)); //+ 2 to allocate space for the "\0" Placeholder and the final NULL
	if (!array)
		return (NULL);
	while (words-- >= 0)
	{
		if (i == 0)
		{
			array[i] = malloc(sizeof(char));
			if (!array[i])
				return (NULL);
			array[i++][0] = '\0';
			continue ;
		}
		array[i++] = fill_words(s, c);
	}
	array[i] = NULL;
	return (array);
}
