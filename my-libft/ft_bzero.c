/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:03:45 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/25 15:08:19 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = (char *)s;
	while (n > 0)
	{
		*ptr++ = '\0';
		n--;
	}
}
/* 
int	main(void)
{
	char str1[] = "chocolate";
	ft_bzero(str1, 0);
	printf ("%s\n", str1);
	char str[] = "chocolate";
	ft_bzero(str, 0);
	printf ("%s\n", str);
} */