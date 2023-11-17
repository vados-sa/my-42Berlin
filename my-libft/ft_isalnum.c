/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:39:24 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/14 12:17:59 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

int	ft_isalnum(int c);

int	ft_isalnum(int c)
{
	return ((c >= 97 && c <= 122) 
		|| (c >= 65 && c <= 90)
		|| (c >= 48 && c <= 57));
}

/* int	main(void)
{
	char	c;

	c = '5';
	printf("%d\n", isalnum(c));
	printf("%d\n", ft_isalnum(c));
	return (0); 
} */
