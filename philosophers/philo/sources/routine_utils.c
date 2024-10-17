/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:21:11 by vados-sa          #+#    #+#             */
/*   Updated: 2024/10/17 17:52:57 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/**
 * Checks the philosopher's life status.
 * @philo: Pointer to the philosopher data.
 * 
 * This function checks whether the philosopher is still alive by locking the
 * state mutex, retrieving the philosopher's life status, and unlocking the mutex.
 * 
 * Return: The philosopher's life status (either ALIVE or DEAD).
 */
static int	check_state(t_philo *philo)
{
	int	live;

	pthread_mutex_lock(&philo->data->state_mutex);
	live = philo->life_status;
	pthread_mutex_unlock(&philo->data->state_mutex);
	return (live);
}

/**
 * Philosopher takes forks and starts eating.
 * @philo: Pointer to the philosopher data.
 * 
 * This function controls how a philosopher picks up the forks. Philosophers
 * with even IDs pick up the left fork first, then the right fork, while odd
 * IDs pick up the right fork first, then the left, to avoid deadlocks. After 
 * taking both forks, the philosopher begins eating.
 */
static void	line_to_eat(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
	print_status(philo, "is eating");
}

/**
 * Philosopher performs the eating action.
 * @philo: Pointer to the philosopher data.
 * 
 * This function makes the philosopher eat by taking the necessary forks using
 * `line_to_eat`. It updates the last meal time, increments the meal count, and
 * checks if the philosopher has eaten the required number of meals. After eating,
 * the philosopher releases both forks.
 * 
 * Return: 1 if the philosopher dies while eating, 0 if the philosopher is still alive,
 * or FULL if the philosopher has eaten the required number of meals.
 */
int	eat(t_philo *philo)
{
	if (check_state(philo) == DEAD)
		return (1);
	line_to_eat(philo);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal_t = get_time();
	pthread_mutex_unlock(&philo->data->meal_mutex);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->count_meals++;
	if (philo->count_meals == philo->nbr_of_meals)
	{
		philo->full = FULL;
		pthread_mutex_unlock(&philo->data->meal_mutex);
		return (FULL);
	}
	pthread_mutex_unlock(&philo->data->meal_mutex);
	return (0);
}

/**
 * Philosopher performs the sleeping action.
 * @philo: Pointer to the philosopher data.
 * 
 * This function makes the philosopher sleep for a specified amount of time
 * (`time_to_sleep`). The philosopher sleeps only if they are still alive.
 * 
 * Return: 1 if the philosopher dies while sleeping, 0 if the philosopher is still alive.
 */
int	nap(t_philo *philo)
{
	if (check_state(philo) == DEAD)
		return (1);
	print_status(philo, "is sleeping");
	usleep(philo->time_to_sleep * 1000);
	return (0);
}

/**
 * Philosopher performs the thinking action.
 * @philo: Pointer to the philosopher data.
 * 
 * This function makes the philosopher think for a time derived from the difference
 * between `time_to_die`, `time_to_eat`, and `time_to_sleep`. The philosopher thinks
 * only if they are still alive.
 * 
 * Return: 1 if the philosopher dies while thinking, 0 if the philosopher is still alive.
 */
int	think(t_philo *philo)
{
	if (check_state(philo) == DEAD)
		return (1);
	print_status(philo, "is thinking");
	usleep((philo->time_to_die - philo->time_to_eat - \
		philo->time_to_sleep) / 2 * 1000);
	return (0);
}
