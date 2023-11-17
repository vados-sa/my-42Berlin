/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:33:33 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/14 14:24:55 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

int	ft_tolower(int c);

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
/* 
int	main(void)
{
	char	c;

	c = '9';
	printf("funtion: %c.\nindent.: %c.\n", tolower(c), ft_tolower(c));
	return (0);
} */
