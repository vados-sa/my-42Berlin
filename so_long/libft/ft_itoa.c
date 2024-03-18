/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 10:35:25 by vados-sa          #+#    #+#             */
/*   Updated: 2023/11/30 10:49:54 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n);
static char	*alloc_mem(int len);

static int	ft_intlen(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n <= 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static char	*alloc_mem(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	int			len;
	int			i;
	char		*s;

	nbr = n;
	len = ft_intlen(nbr);
	s = alloc_mem(len);
	if (!s)
		return (NULL);
	if (nbr < 0)
	{
		nbr = -nbr;
		s[0] = '-';
	}
	i = len - 1;
	while (nbr)
	{
		s[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	s[len] = '\0';
	return (s);
}
