#include "ft_printf.h"

int	print_char(int len, int c)
{
	write (1, &c, 1);
	len++;
	return(len);
}