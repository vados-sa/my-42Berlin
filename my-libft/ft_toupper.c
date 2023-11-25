/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:33:20 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/25 15:12:21 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
/* 
int	main(void)
{
	char	c;

	c = 'C';
	printf("funtion: %c.\nindent.: %c.\n", toupper(c), ft_toupper(c));
	return (0);
}
*/
