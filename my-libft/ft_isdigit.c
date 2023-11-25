/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:19 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/25 15:04:40 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
/* 
int	main(void)
{
	char	c;

	c = '5';
	printf("%d\n", isdigit(c));
	printf("%d\n", ft_isdigit(c));
	return (0); 
} */
