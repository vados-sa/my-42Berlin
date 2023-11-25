/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:48:00 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/25 15:11:15 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (i < size - 1 && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (i);
}
/* 
int	main(void)
{
	char	src[] = " S";
	char	dest[15] = "Vanessa";
	printf ("Size of concatenated str: %zu.\n", ft_strlcat(dest, src, sizeof(dest)));
	printf ("Concatenated string: %s.\n", ft_strlcat(dest, src, sizeof(dest)));
	return (0);
} */