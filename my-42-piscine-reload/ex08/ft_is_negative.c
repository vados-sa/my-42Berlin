#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_is_negative(int n)
{
    if (n < 0)
        ft_putchar('N');
    else
        ft_putchar('P');
}

int     main()
{
    ft_is_negative(10);
    ft_is_negative(0);
    ft_is_negative(-10);
    return 0;
}