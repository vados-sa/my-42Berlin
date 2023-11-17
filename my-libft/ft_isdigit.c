/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:22:19 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/14 14:27:04 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

int	ft_isdigit(int c);

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
