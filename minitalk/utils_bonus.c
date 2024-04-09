#include "minitalk_bonus.h"

void	error_exit(void)
{
	ft_printf("\nError\n\n");
	exit(1);
}

void	send_bit(char c, int pid)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				error_exit();
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error_exit();
		}
		usleep(1115);
		i--;
	}
}
