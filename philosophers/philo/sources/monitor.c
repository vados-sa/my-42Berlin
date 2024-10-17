/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:21:09 by vados-sa          #+#    #+#             */
/*   Updated: 2024/10/17 17:49:12 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * Checks if a philosopher has starved to death.
 * @philo: Pointer to the philosopher data.
 * 
 * This function calculates the elapsed time since the philosopher's last meal.
 * If the elapsed time exceeds the time the philosopher can survive without eating
 * (`time_to_die`), and the philosopher is still hungry, it marks the philosopher
 * as dead and prints the "died" status.
 * 
 * Return: 1 if the philosopher has died from starvation, 0 otherwise.
 */
static int	check_starvation(t_philo *philo)
{
	uint64_t		current_time_ms;
	uint64_t		elapsed_time_ms;

	current_time_ms = get_time();
	pthread_mutex_lock(&philo->data->meal_mutex);
	elapsed_time_ms = current_time_ms - philo->last_meal_t;
	if (elapsed_time_ms >= philo->data->time_to_die && (philo->full == HUNGRY))
	{
		pthread_mutex_unlock(&philo->data->meal_mutex);
		print_status(philo, "died");
		return (1);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (0);
}

/**
 * Marks all philosophers as dead.
 * @data: Pointer to the shared data structure.
 * 
 * This function updates the life status of all philosophers to `DEAD`
 * when a philosopher dies, effectively stopping the simulation.
 */
static void	announce_death(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&data->state_mutex);
	while (i < (int)data->nbr_of_philo)
		data->philo[i++].life_status = DEAD;
	pthread_mutex_unlock(&data->state_mutex);
}

/**
 * Retrieves the number of meals a philosopher has eaten.
 * @philo: Pointer to the philosopher data.
 * 
 * This function locks the meal mutex and checks how many meals the philosopher
 * has consumed so far. It returns the count of meals eaten.
 * 
 * Return: The number of meals eaten by the philosopher.
 */
static int	check_meals(t_philo *philo)
{
	int	meals_done;

	pthread_mutex_lock(&philo->data->meal_mutex);
	meals_done = philo->count_meals;
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (meals_done);
}

/**
 * Tracks the total number of meals eaten by all philosophers.
 * @data: Pointer to the shared data structure.
 * @total_meals: The current total number of meals consumed by all philosophers.
 * 
 * This function checks if all philosophers have eaten the required number of meals.
 * If every philosopher has eaten the specified number of meals (`nbr_of_meals`), 
 * it returns 1 to stop the simulation.
 * 
 * Return: 1 if all philosophers have eaten the required meals, 0 otherwise.
 */
static int	track_meals(t_data *data, uint64_t total_meals)
{
	if (data->nbr_of_philo == 1 || !data->nbr_of_meals)
		return (0);
	if (total_meals == data->nbr_of_philo * data->nbr_of_meals)
		return (1);
	return (0);
}

/**
 * Monitors the philosophers for starvation or completion.
 * @data: Pointer to the shared data structure.
 * 
 * This function continuously monitors all philosophers for two conditions:
 * 1. If any philosopher has starved to death.
 * 2. If all philosophers have eaten the required number of meals.
 * 
 * If a philosopher dies, the simulation stops and their death is announced.
 * If all philosophers have finished their meals, the simulation ends gracefully.
 * 
 * Return: NULL when the monitoring stops, either due to a philosopher's death 
 * or all philosophers finishing their meals.
 */
void	*monitor(t_data *data)
{
	int	i;
	int	starved;
	int	total_meals;

	while (1)
	{
		i = 0;
		total_meals = 0;
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
			if (track_meals(data, total_meals))
				return (NULL);
		}
	}
	return (NULL);
}
