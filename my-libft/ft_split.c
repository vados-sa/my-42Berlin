/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:45 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/29 12:24:53 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c);
static int	count_char(char const *s, char c);
static char	**copy_words(char const *s, char c);

/*This functio counts the amount of words/ subtrings.*/
static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		if (s[i] != c)
        {
            count++;
            while (s[i] != c && s[i])
                i++;
        }
		else
        {
			while (s[i] == c && s[i])
            	i++;
        }
	}
	return (count);
}
/*This function counts the amount of non delimiter characters,
for exact memory allocation*/
static int	count_char(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		count++;
	}
	return (count);
}
/*This function will make a copy of the substirngs,
while dinamically allocating memory for them.*/
static char	**copy_words(char const *s, char c)
{
	const char 	*start;
	char		**array;
	int			i;
	int			j;
	int			len;

	i = 0;
	while(*s)
	{
		start = s;
		while (*s && *s != c)
			s++;
		len = s - start;
		array[i] = (char *)malloc((len +1) * sizeof(char));
		if(!array[i])
			return (NULL);
		j = 0;
		while (start < s)
			array[i][j++] = *start++;
		array[i][j] = '\0';
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	int		characters;
	char 	**array;

	words = count_words(s, c);
	characters = count_char(s, c);
	array = (char **)malloc((characters + words + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (*s)
	{
		if (*s != c)
			array = copy_words(s, c);
		else
			s++;
	}
	return (array);
}

int	main(void)
{
	size_t	i;
	
	char **result = ft_split("Hello,World,How,Are,You", ',');
	i = 0;
	while (result[i] != NULL)
	{
		printf("Substring %d: %s\n", i, result[i]);
		i++;
	}
	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}