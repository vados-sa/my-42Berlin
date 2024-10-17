/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_manage.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:21:06 by vados-sa          #+#    #+#             */
/*   Updated: 2024/10/16 12:34:10 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	print_error_exit(char *message, int exit_code)
{
	printf("%s\n", message);
	exit(exit_code);
}

static void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < (int)data->nbr_of_philo)
		pthread_join(data->philo[i++].thread, NULL);
}

static void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < (int)data->nbr_of_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->state_mutex);
}

void	cleanup(t_data *data, char *message, int exit_code)
{
	if (exit_code == EXIT_SUCCESS)
	{
		join_threads(data);
		destroy_mutexes(data);
	}
	if (message)
		printf("%s\n", message);
	if (data->philo)
		free (data->philo);
	if (data->forks)
		free (data->forks);
	free(data);
	exit(exit_code);
}
