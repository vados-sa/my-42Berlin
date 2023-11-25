/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:16:02 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/25 15:10:04 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	if (d > s)
	{
		i = n;
		while (i-- > 0)
			d[i] = s[i];
	}
	else
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dest);
}
/* 
int	main(void)
{
	char source[] = "Copycat";
	char	destination[7];
	char	dest[7];

	printf("Original Source: %s\n", source);

	memmove(destination, source + 2, 4);
	printf("Destination (memmove): %s\n", destination);

	ft_memmove(dest, source + 2, 4);
	printf("Dest. (ft_memmove): %s\n", dest);

	return (0);
} */