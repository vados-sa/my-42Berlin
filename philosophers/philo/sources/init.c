/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 15:21:02 by vados-sa          #+#    #+#             */
/*   Updated: 2024/10/17 17:29:24 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	*init_forks(t_data *data)
{
	int	i;
	int	n_philos;

	i = 0;
	n_philos = data->nbr_of_philo;
	data->forks = malloc(n_philos * sizeof(pthread_mutex_t));
	if (!data->forks)
		cleanup(data, "Error initializing fork data!", EXIT_FAILURE);
	while (i < (int)n_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
		{
			while (i-- > 0)
				pthread_mutex_destroy(&data->forks[i]);
			cleanup(data, "Error initializing fork mutex!", EXIT_FAILURE);
		}
		i++;
	}
	return (NULL);
}

static void	mutex_init(t_data *data)
{
	if (pthread_mutex_init(&data->print_mutex, NULL))
		cleanup(data, "Error initializing print mutex!", EXIT_FAILURE);
	if (pthread_mutex_init(&data->state_mutex, NULL))
	{
		pthread_mutex_destroy(&data->print_mutex);
		cleanup(data, "Error initializing state mutex!", EXIT_FAILURE);
	}
	if (pthread_mutex_init(&data->meal_mutex, NULL))
	{
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->state_mutex);
		cleanup(data, "Error initializing meal mutex!", EXIT_FAILURE);
	}
}

static void	philo_info_init(t_data *data, int i)
{
	data->philo[i].id = i + 1;
	data->philo->count_meals = 0;
	data->philo[i].life_status = ALIVE;
	data->philo[i].full = HUNGRY;
	data->philo[i].nbr_of_meals = (int)data->nbr_of_meals;
	data->philo[i].time_to_die = data->time_to_die;
	data->philo[i].time_to_eat = data->time_to_eat;
	data->philo[i].time_to_sleep = data->time_to_sleep;
	data->philo[i].last_meal_t = data->start_time;
	data->philo->thread = 0;
	data->philo[i].left_fork = &data->forks[i];
	if (data->nbr_of_philo > 1)
		data->philo[i].right_fork = &data->forks[(i + 1) % data->nbr_of_philo];
	else
		data->philo[i].right_fork = 0;
	data->philo[i].data = data;
}

static void	philo_init(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(data->nbr_of_philo * sizeof(t_philo));
	if (!data->philo)
		cleanup(data, "Error initializing philo data!", EXIT_FAILURE);
	while (i < ((int)data->nbr_of_philo))
	{
		philo_info_init(data, i);
		i++;
	}
}

t_data	*init_data(int ac, char *av[])
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
	{
		printf("Error initializing data!\n");
		exit (EXIT_FAILURE);
	}
	memset(data, 0, sizeof(t_data));
	data->start_time = get_time();
	data->nbr_of_philo = ft_custom_atoi(av[1]);
	data->time_to_die = ft_custom_atoi(av[2]);
	data->time_to_eat = ft_custom_atoi(av[3]);
	data->time_to_sleep = ft_custom_atoi(av[4]);
	if (ac == 6)
		data->nbr_of_meals = ft_custom_atoi(av[5]);
	init_forks(data);
	mutex_init(data);
	philo_init(data);
	return (data);
}
