/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:37:24 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/14 12:13:14 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

int	ft_isalpha(int c);

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
