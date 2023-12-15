#include "ft_printf.h"

static int ft_putnbr_base(int nbr, char *base);

static int ft_putnbr_base(int nbr, char *base)
{
	long int	len;
	long int	n;
	int			i;

	len = ft_strlen(base);
	n = nbr;
	i = 0;
	if (base)
	{
		if (n < 0)
		{
			i += print_char('-');
			n *= -1;
		}
		if (n < len)
			i += print_char(base[n]);
		if (n >= len)
		{
			i += ft_putnbr_base(n / len, base);
			i += ft_putnbr_base(n % len, base);
		}
		if (i < 0)
			return (-1);
	}
	return (i);
}

int	print_sign_dec_int(int number)
{
	int			i;
	long int	n;

	n = number;
	i = 0;
	i += ft_putnbr_base(n, "0123456789");
	if (i <= 0)
		return (-1);
	return (i);
}

/* int	main()
{
	char *base = "0123456789";

	int num1 = 123456;
	ft_putnbr_base(num1, base);
	printf("\n");
	printf("%i\n", num1);

	int num2 = -42;
	ft_putnbr_base(num2, base);
	printf("\n");
	printf("%i\n", num2);
	int num3 = -987654321;
	ft_putnbr_base(num3, base);
	printf("\n");
	printf("%i\n", num3);

	//octal
	int num4 = 042;
	ft_putnbr_base(num4, base);
	printf("\n");
	printf("%i\n", num4);

	//haxadecimal
	int num5 = 0x1A3;
	ft_putnbr_base(num5, base);
	printf("\n");
	printf("%i\n", num5);
	
	return (0);
} */