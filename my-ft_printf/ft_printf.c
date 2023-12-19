/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:14:22 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/19 11:14:10 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	form_specif(const char *format, va_list args, int count);

static int	form_specif(const char *format, va_list args, int count)
{
	if (*(format + 1) == 'c')
		count += print_char(va_arg(args, int));
	else if (*(format + 1) == 's')
		count += print_str(va_arg(args, char *));
	else if (*(format + 1) == 'p')
		count += print_pointer(va_arg(args, void *));
	else if (*(format + 1) == 'd' || *(format + 1) == 'i')
		count += print_sign_dec_int(va_arg(args, int));
	else if (*(format + 1) == 'u')
		count += print_unsign_dec_int(va_arg(args, int));
	else if (*(format + 1) == 'x')
		count += print_hex_int_low(va_arg(args, int));
	else if (*(format + 1) == 'X')
		count += print_hex_int_upper(va_arg(args, int));
	else if (*(format + 1) == '%')
		count += print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			count += form_specif(format, args, 0);
			if (count < 0)
				return (-1);
			format += 2;
		}
		else
		{
			if (write(1, format++, 1) == -1)
				return (-1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
