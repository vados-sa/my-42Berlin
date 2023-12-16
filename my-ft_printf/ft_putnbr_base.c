#include "ft_printf.h"

int ft_putnbr_base(int nbr, char *base)
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