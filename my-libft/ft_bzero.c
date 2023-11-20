/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:03:45 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/20 15:33:27 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n);

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	unsigned int	i;

	i = 0;
	ptr = (unsigned char *)s;
	/* if (n == 0)
		return (0); */
	while (i < n)
	{
		*ptr = '\0';
		ptr++;
		i++;
	}
}

int	main(void)
{
	char str1[] = "chocolate";
	ft_bzero(str1, 0);
	printf ("%s\n", str1);
	char str[] = "chocolate";
	ft_bzero(str, 0);
	printf ("%s\n", str);
}