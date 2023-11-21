/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:39:41 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/21 10:44:18 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == 0 && src == 0)
		return (dest);
	d = dest;
	s = src; 
	while ((n > 0))
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}
/* 
int main(void) {
	char source[] = "Copycat";
	char destination[20];
	char dest[20];

	destination[8] = '\0';
	dest[8] = '\0';

	printf("Destination: %s\n", (char *)memcpy(destination, source, 7));
	printf("Dest.: %s\n", (char *)ft_memcpy(dest, source, 7));

	return 0;
} */