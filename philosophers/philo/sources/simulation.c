/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:21:14 by vados-sa          #+#    #+#             */
/*   Updated: 2024/10/17 17:46:42 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * The main routine for each philosopher thread.
 * @arg: Pointer to the philosopher data (casted as void* for pthread compatibility).
 * 
 * This function represents the actions of each philosopher. It starts by
 * updating the philosopher's last meal time, and then enters a loop where the
 * philosopher alternates between eating, sleeping (nap), and thinking.
 * The loop runs indefinitely until the philosopher either finishes all their meals
 * or dies. If the philosopher is the only one, it exits immediately as they cannot
 * proceed without another philosopher.
 * 
 * Return: Always returns NULL, indicating the thread has finished execution.
 */
static void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_t = get_time();
	pthread_mutex_unlock(&philo->data->meal_mutex);
	if (philo->data->nbr_of_philo != 1)
	{
		while (1)
		{
			if (eat(philo))
				return (NULL);
			if (nap(philo))
				return (NULL);
			if (think(philo))
				return (NULL);
		}
	}
	return (NULL);
}

/**
 * Initializes the philosopher threads and starts the simulation.
 * @data: Pointer to the shared data structure.
 * 
 * This function creates and starts a thread for each philosopher. Before creating
 * the thread, it updates each philosopher's last meal time. If thread creation fails
 * for any philosopher, it joins and cleans up the already created threads and
 * exits the program with an error. Once all threads are successfully created,
 * the simulation proceeds with 'routine'.
 */
void	simulation(t_data *data)
{
	int	i;
	int	j;
	int	nb_philo;

	i = 0;
	nb_philo = (int)data->nbr_of_philo;
	while (i < nb_philo)
	{
		pthread_mutex_lock(&data->meal_mutex);
		data->philo[i].last_meal_t = get_time();
		pthread_mutex_unlock(&data->meal_mutex);
		if ((pthread_create(&data->philo[i].thread, NULL, \
			&routine, &data->philo[i])))
		{
			printf("Failed to create Philosopher %d.\n", i + 1);
			j = 0;
			while (j < i)
				pthread_join(data->philo[j++].thread, NULL);
			cleanup(data, NULL, EXIT_FAILURE);
		}
		i++;
	}
}
