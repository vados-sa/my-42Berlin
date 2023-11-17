/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:33:20 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/14 14:26:39 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

int	ft_toupper(int c);

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
