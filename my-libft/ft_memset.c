/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:38:38 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/20 11:40:38 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <stdio.h>
#include <string.h> */

void	*ft_memset(void *s, int c, size_t n);

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		*ptr = (unsigned char)c;
		ptr++;
		i++;
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