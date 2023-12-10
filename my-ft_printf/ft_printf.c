#include "ft_printf.h"

/* static int	print_format(int len, const char *format); */
static int	print_c(int len, int c);

static int	print_c(int len, int c)
{
	write (1, &c, 1);
	len++;
	return(len);
}

/* static int	print_format(int len, const char *format)
{
	while (format[len] && format[len] != '%')
	{
		write(1, &format[len], 1);
		len++;
	}
	return (len);
} */

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	int	count;

	count = 0;
	while(*format)
	{
		if (*format == '%' && *(format + 1) == 'c')
		{
			count += print_c(0, va_arg(args, int));
			format += 2;
		}
		else
		{
			write(1, format++, 1);
            count++;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	int functionCharsPrinted = printf ("Width and Right Justification: |%5c|\n", 'Z');
	if (functionCharsPrinted < 0)
    	printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", functionCharsPrinted);
	int	charsPrinted = ft_printf ("Width and Right Justification: |%5c|\n", 'Z');
	if (charsPrinted < 0)
    	printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", charsPrinted);
	return (0);
}