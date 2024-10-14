/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:21:19 by vados-sa          #+#    #+#             */
/*   Updated: 2024/10/14 14:29:59 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philo.h"

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->state_mutex);
	if (philo->life_status == ALIVE)
	{
		pthread_mutex_unlock(&philo->data->state_mutex);
		pthread_mutex_lock(&philo->data->print_mutex);
		printf("%" PRIu64 " %d %s\n", (get_time() - \
		philo->data->start_time), philo->id, status);
		pthread_mutex_unlock(&philo->data->print_mutex);
	}
	else
		pthread_mutex_unlock(&philo->data->state_mutex);
}

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((uint64_t)tv.tv_sec * 1000) + ((uint64_t)tv.tv_usec / 1000));
}

uint64_t	ft_custom_atoi(const char *s)
{
	int			i;
	uint64_t	nbr;

	i = 0;
	while ((s[i] == ' ') || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (!s[i] || s[i] == '-' || ((s[i] == '+')
			&& !(s[i + 1] >= '0' && s[i + 1] <= '9')))
		return (-1);
	if (s[i] == '+')
		i++;
	nbr = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (-1);
		nbr = nbr * 10 + (s[i] - '0');
		i++;
	}
	if (nbr > INT_MAX)
		return (-1);
	return (nbr);
}
