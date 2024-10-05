/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:21:09 by vados-sa          #+#    #+#             */
/*   Updated: 2024/10/05 15:45:07 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	check_starvation(t_philo *philo);
static void	announce_death(t_data *data);
static int	check_meals(t_philo *philo);
static int	track_meals(t_data *data, uint64_t total_meals);

void	*monitor(t_data *data)
{
	int	i;
	int	starved;
	int	total_meals;

	total_meals = 0;
	//printf("starting monitor routine.\n");
	while (1)
	{
		precise_usleep(500);
		i = 0;
		while (i < (int)data->nbr_of_philo)
		{
			starved = check_starvation(&data->philo[i]);
			if (starved)
			{
				announce_death(data);
				return (NULL);
			}
			total_meals += check_meals(&data->philo[i]);
			i++;
		}
		if (track_meals(data, total_meals))
			return (NULL); // monitor doesn't let them know they should stop.
	}
	return (NULL);
}

static int	check_starvation(t_philo *philo)
{
	uint64_t		current_time_ms;
	uint64_t		elapsed_time_ms;

	current_time_ms = get_time();
	pthread_mutex_lock(&philo->data->meal_mutex);
	elapsed_time_ms = current_time_ms - philo->last_meal_t;
	if (elapsed_time_ms >= philo->data->time_to_die/*  && (philo->full == HUNGRY) */)
	{
		pthread_mutex_unlock(&philo->data->meal_mutex);
		print_status(philo, "died");
		return (1);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (0);
}

static void	announce_death(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->state_mutex);
	//data->life_status = DEAD;
	while (i < (int)data->nbr_of_philo)
		data->philo[i++].life_status = DEAD;
	pthread_mutex_unlock(&data->state_mutex);
}

static int	check_meals(t_philo *philo)
{
	int	meals_done;

	pthread_mutex_lock(&philo->data->meal_mutex);
	meals_done = philo->count_meals;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (meals_done);
}

static int	track_meals(t_data *data, uint64_t total_meals)
{
	if (data->nbr_of_philo == 1 || !data->nbr_of_meals)
		return (0);
	if (total_meals == data->nbr_of_philo * data->nbr_of_meals)
		return (1);
	return (0);
}
