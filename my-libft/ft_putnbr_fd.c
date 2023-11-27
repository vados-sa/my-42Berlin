#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -nbr;
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}
int main(void)
{
    int number1 = 123;
    int number2 = -456;
    int number3 = 0;

    // Test with positive number
    ft_putnbr_fd(number1, 1); // Assuming 1 is the file descriptor for standard output
    ft_putchar_fd('\n', 1);

    // Test with negative number
    ft_putnbr_fd(number2, 1);
    ft_putchar_fd('\n', 1);

    // Test with zero
    ft_putnbr_fd(number3, 1);
    ft_putchar_fd('\n', 1);

    return 0;
}