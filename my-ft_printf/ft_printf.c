#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	int	count;

	count = 0;
	while(*format)
	{
		if (*format == '%')
		{
			if (*(format + 1) == 'c')
				count += print_char((char) va_arg(args, int));
			if (*(format + 1) == 's')
				count += print_str((char *) va_arg(args, char *));
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
	int functionCharsPrinted = printf ("Characters: %c %c, Strings: %s %s\n", 'X', 'Y', "Good", "Bad");
	if (functionCharsPrinted < 0)
		printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", functionCharsPrinted);
	//implementation
	int	charsPrinted = ft_printf ("Characters: %c %c, Strings: %s %s\n", 'X', 'Y', "Good", "Bad");
	if (charsPrinted < 0)
		printf("ft_printf failed");
	else
		printf("Number of characters printed: %d\n", charsPrinted);
	return (0);
}