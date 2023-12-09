#include "ft_printf.h"

static int	print_format(const char *format);

static int	print_format(const char *format)
{
	int	len;

	len = 0;
	while (format[len])
	{
		write(1, &format[len], 1);
		len++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int	len;

	len = print_format(format);
	return (len);
}

int	main(void)
{
	char	*s = "Vanessa";
	printf ("This is a %string\n", s);
	int	charsPrinted = ft_printf ("A string.\n");
	if (charsPrinted < 0)
    	printf("printf failed");
	else
		printf("Number of characters printed: %d\n", charsPrinted);
	return (0);
}