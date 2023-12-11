#ifndef FT_PRINTF_H

#define FT_PRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_char(int len, int c);

#endif