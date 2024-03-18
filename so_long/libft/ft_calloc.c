/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:51:57 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/30 10:53:36 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t			i;
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
