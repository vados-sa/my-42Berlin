/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:39:41 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/23 15:31:23 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == (void *)0 && src == (void *)0)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src; 
	while ((n > 0))
	{
		*d++ = *s++;
		n--;
	}
	return (dest);
}
/* 
int main(void) {
	char source[] = "Copykitty";
	char destination[10];
	char dest[10];

	printf("Destination: %s\n", (char *)memcpy(destination, source + 2, 7));
	printf("Dest.:       %s\n", (char *)ft_memcpy(dest, source + 2, 7));
	//null terminate in the main?
	return 0;
} */