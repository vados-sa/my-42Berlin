#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include "./ft_printf/ft_printf.h"
#include "./libft/libft.h"

void	error_exit(void);
void	send_bit(char c, int pid);

#endif