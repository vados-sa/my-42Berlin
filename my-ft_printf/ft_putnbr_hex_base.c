#include "ft_printf.h"

int ft_putnbr_hex_base(unsigned int nbr, unsigned int baseLen, char *base)
{
    int i;

    i = 0;
    if (nbr < baseLen)
        i += print_char(base[nbr]);
    if (nbr >= baseLen)
    {
        i += ft_putnbr_hex_base(nbr / baseLen, baseLen, base);
        i += ft_putnbr_hex_base(nbr % baseLen, baseLen, base);
    }
    if (i < 0)
        return (-1);
    return (i);
}