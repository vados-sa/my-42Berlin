#include "libft.h"

long long	ft_atoll(const char *str)
{
	long long	res;
	int	sign;

	res = 0;
	sign = 1;
	while ((*str == ' ') || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}
