/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex_int_low.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:14:25 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/20 12:34:56 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_hex_int_low(unsigned int nbr)
{
	return (ft_putnbr_hex_base(nbr, "0123456789abcdef"));
}
