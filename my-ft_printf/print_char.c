#include "ft_printf.h"

int	print_char(char c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return(1);
}