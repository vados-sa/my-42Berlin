/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:11:36 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/20 12:35:28 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
