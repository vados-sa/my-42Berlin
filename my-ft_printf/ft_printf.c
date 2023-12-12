/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:14:22 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/12 14:06:19 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//TO DO:
//- %p
//- %d
//- %i
//- %u
//- %x
//- %X
static int	form_specif(const char *format, va_list args, int count);

static int	form_specif(const char *format, va_list args, int count)
{
	if (*(format + 1) == 'c')
		count += print_char((char) va_arg(args, int));
	if (*(format + 1) == 's')
		count += print_str((char *) va_arg(args, char *));
	if (*(format + 1) == '%')
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

/* int	main(void)
{
	//function
	int functionCharsPrinted = printf ("Characters: %c %c, %%Strings: %s %s\n", 'X', 'Y', "Good", "Bad");
	if (functionCharsPrinted < 0)
		printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", functionCharsPrinted);
	//implementation
	int	charsPrinted = ft_printf ("Characters: %c %c, %%Strings: %s %s\n", 'X', 'Y', "Good", "Bad");
	if (charsPrinted < 0)
		printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", charsPrinted);
	return (0);
} */