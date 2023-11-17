/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:56:07 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/14 12:12:29 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include <ctype.h>
#include <stdio.h> */

int	ft_isprint(int c);

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