/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vanessasantos <vanessasantos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:14:22 by vados-sa          #+#    #+#             */
/*   Updated: 2023/12/18 09:54:12 by vanessasant      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//TO DO:
//- %p
//- %x
//- %X
static int	form_specif(const char *format, va_list args, int count);

static int	form_specif(const char *format, va_list args, int count)
{
	if (*(format + 1) == 'c')
		count += print_char((char) va_arg(args, int));
	else if (*(format + 1) == 's')
		count += print_str((char *) va_arg(args, char *));
	else if (*(format + 1) == 'd' || *(format + 1) == 'i')
		count += print_sign_dec_int(va_arg(args, int));
	else if (*(format + 1) == 'u')
		count += print_unsign_dec_int(va_arg(args, int));
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

/* int	main(void)
{
	char charValue = 'A';
    const char *stringValue = "Hello, World!";
    int intValue = -42;
    unsigned int uintValue = 12345;
	//function
	int functionCharsPrinted = printf ("Character: %c, String: %s, Integer: %d, Integer: %i, Unsigned Integer: %u, Percent Sign: %%\n", charValue, stringValue, intValue, intValue, uintValue);
	if (functionCharsPrinted < 0)
		printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", functionCharsPrinted);
	//implementation
	int	charsPrinted = ft_printf ("Character: %c, String: %s, Integer: %d, Integer: %i, Unsigned Integer: %u, Percent Sign: %%\n", charValue, stringValue, intValue, intValue, uintValue);
	if (charsPrinted < 0)
		printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", charsPrinted);
	return (0);
} */