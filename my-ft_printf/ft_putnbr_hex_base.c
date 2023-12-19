/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:11:36 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/19 11:06:53 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex_base(unsigned int nbr, char *base)
{
	unsigned int	base_len;
	int				i;

	i = 0;
	base_len = ft_strlen(base);
	if (nbr < base_len)
		i += print_char(base[nbr]);
	if (nbr >= base_len)
	{
		i += ft_putnbr_hex_base(nbr / base_len, base);
		i += ft_putnbr_hex_base(nbr % base_len, base);
	}
	if (i < 0)
		return (-1);
	return (i);
}
