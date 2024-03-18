/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:16:29 by vados-sa          #+#    #+#             */
/*   Updated: 2024/03/05 16:27:06 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

int	ft_putnbr_base(int nbr, char *base)
{
	long int	len;
	long int	n;
	int			i;

	len = ft_strlen(base);
	n = nbr;
	i = 0;
	if (base)
	{
		if (n < 0)
		{
			i += print_char('-');
			n *= -1;
		}
		if (n < len)
			i += print_char(base[n]);
		if (n >= len)
		{
			i += ft_putnbr_base(n / len, base);
			i += ft_putnbr_base(n % len, base);
		}
		if (i < 0)
			return (-1);
	}
	return (i);
}

int	ft_putnbr_base_unsign(unsigned int nbr, char *base)
{
	long int	len;
	int			i;

	len = ft_strlen(base);
	i = 0;
	if (base)
	{
		if (nbr < len)
			i += print_char(base[nbr]);
		if (nbr >= len)
		{
			i += ft_putnbr_base_unsign(nbr / len, base);
			i += ft_putnbr_base_unsign(nbr % len, base);
		}
		if (i < 0)
			return (-1);
	}
	return (i);
}

int	ft_putnbr_hex_base(unsigned long long nbr, char *base)
{
	int				i;

	i = 0;
	if (nbr <= 15)
		i += print_char(base[nbr]);
	if (nbr > 15)
	{
		i += ft_putnbr_hex_base(nbr / 16, base);
		i += ft_putnbr_hex_base(nbr % 16, base);
	}
	return (i);
}
