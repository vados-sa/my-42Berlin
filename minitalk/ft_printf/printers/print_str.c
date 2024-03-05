/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:21:20 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/20 12:35:12 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += print_str("(null)");
		return (count);
	}
	else
	{
		while (*s)
		{
			count += print_char(*s);
			s++;
		}
	}
	return (count);
}
