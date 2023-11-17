/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:58:16 by vanessasant       #+#    #+#             */
/*   Updated: 2023/11/16 23:27:10 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t ft_strlcpy(char *dest, const char *src, size_t size);

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	while (i < (size - 1) && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i); 
	
}

int	main(void)
{
	char	src[] = "Vanessa";
	char	dest[5];
	
	printf("Length of copied string: %zu.\nCopied string: %s\n", ft_strlcpy(dest, src, sizeof(dest)), dest);
	return (0);
}