/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:33:21 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/25 15:15:32 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	uc;
	size_t			i;

	str = (unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}

/* int	main(void)
{
	char str[] = "abacate";
	void *result = ft_memchr(str, 'p', 7);
	if (result != NULL)
		printf ("%c\n", *((char *)result));
	//The cast (char *)result is used to treat the result
	//as a pointer to a character, 
	//and *((char *)result) dereferences the pointer
	//to get the actual character.
	//else
        printf("Character not found.\n");
	return (0);
} */