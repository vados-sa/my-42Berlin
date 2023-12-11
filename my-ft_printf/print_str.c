#include "ft_printf.h"

int	print_str(char *s)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += print_str("(null)");
		return (count);
	}
	else
	{
		while(*s)
		{
			count += print_char(*s);
			s++;
		}
	}
	return(count);
}