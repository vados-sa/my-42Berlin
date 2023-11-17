/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:10:07 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/14 12:22:49 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/* 
int	main(void)
{
	char	c;

	c = 'ç';
	printf("function: %d.\nimplementation: %d.\n", isascii(c), ft_isascii(c));
} */
