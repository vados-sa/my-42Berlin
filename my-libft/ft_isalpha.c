/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:37:24 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/25 15:06:47 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 97 && c <= 122) || (c >= 65 && c <= 90));
}
/* 
int	main(void)
{
	char	c;

	c = 'a';
	printf("%d\n", isalpha(c));
	printf("%d\n", ft_isalpha(c));
	return (0); 
} */
