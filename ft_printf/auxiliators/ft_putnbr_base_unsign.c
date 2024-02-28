/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsign.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:10:22 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/20 12:35:20 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
