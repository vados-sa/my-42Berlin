/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:56:07 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/25 15:06:21 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/* int	main(void)
{
	char	c;

	c = ' ';
	printf("function: %d.\nimplementation: %d.\n", isprint(c), ft_isprint(c));
	return (0);
} */