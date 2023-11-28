/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:53:45 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/28 14:10:11 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	*array;
	char	**words;

	if (!s || !c)
		return (NULL);
	i = 0;
	array = s;
	while (ft_strchr(array[i], c) == 0)
	{
		if (ft_strchr(array[i], c))
		{
			words = (char **)malloc(sizeof(char *));
			if (!words)
				return (NULL);
			words = ft_strchr(s[i + 1], c);
		}
		i++;
	}
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
	return (0);
}