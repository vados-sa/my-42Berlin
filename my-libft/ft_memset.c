/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:38 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/25 15:07:53 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr++ = (unsigned char)c;
		n--;
	}
	return (s);
}

/* int main() 
{
	size_t	size = 2;
	char 	c = 'V';
	char 	str[20];
	printf("Funtion: %s\n", (char*)memset(str, c, size));
	str[10] = '\0';
	printf("Implementation: %s\n", (char*)ft_memset(str, c, size));
	return 0;
} */