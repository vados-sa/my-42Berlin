/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:51:57 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/25 15:17:48 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	i;
	unsigned char	*ptr;

	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < nitems * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
/* 
int	main(void)
{
	size_t nitems = 5;
    size_t size = sizeof(int);
	ft_calloc(nitems, size);
	free (ft_calloc(nitems, size));
	return (0);
} */