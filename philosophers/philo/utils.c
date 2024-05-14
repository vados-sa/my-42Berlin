#include "philo.h"

long long	timeval_to_microsecond(struct timeval tv)
{
	return((long long)tv.tv_sec * 1000000 + tv.tv_usec);
}

int	ft_custom_atoi(const char *s)
{
	int	i;
	unsigned long long	nbr;

	i = 0;
	nbr = 0;
	while ((s[i] == ' ') || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (!s[i] || s[i] == '-' || ((s[i] == '+')
			&& !(s[i + 1] >= '0' && s[i + 1] <= '9')))
		return (-1);
	if (s[i] == '+')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (-1);
		nbr = nbr * 10 + (s[i] - '0');
		i++;
	}
	if (nbr > INT_MAX)
		return (-1);
	return ((int)nbr);
}
