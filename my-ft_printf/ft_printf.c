#include "ft_printf.h"

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
			count += print_char(0, va_arg(args, int));
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
	//function
	int functionCharsPrinted = printf ("Integer Argument: %c\n", 65);
	if (functionCharsPrinted < 0)
    	printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", functionCharsPrinted);
	//implementation
	int	charsPrinted = ft_printf ("Integer Argument: %c\n", 65);
	if (charsPrinted < 0)
    	printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", charsPrinted);
	return (0);
}