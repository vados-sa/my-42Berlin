/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:39:41 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/30 10:42:15 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
