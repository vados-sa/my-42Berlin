#include "philo.h"

t_elements	*init_struct(void)
{
	t_elements	*info;

	info = malloc(sizeof(t_elements));
	if (!info)
	{
		printf("Error initializing arguments!\n");
		exit (EXIT_FAILURE);
	}
	info->nbr_of_philo = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->nbr_of_meals = 0;
	info->start_time = get_time();
	return (info);
}

void	parse_args(int ac, char *av[], t_elements *info)
{
	info->nbr_of_philo = ft_custom_atoi(av[1]);
	info->time_to_die = ft_custom_atoi(av[2]);
	info->time_to_eat = ft_custom_atoi(av[3]);
	info->time_to_sleep = ft_custom_atoi(av[4]);
	info->nbr_of_meals = 0;

	if (info->nbr_of_philo <= 0 || info->time_to_die <= 0 || 
		info->time_to_eat <= 0 || info->time_to_sleep <= 0)
	{
		printf("All input values must be positive integers.\n");
		error_exit(info);
	}
	if (ac == 6)
	{
		info->nbr_of_meals = ft_custom_atoi(av[5]);
		if (info->nbr_of_meals <= 0)
		{
			printf("'number_of_times_each_philosopher_must_eat' must be\
 a positive interger.\n");
			error_exit(info);
		}
	}
}

pthread_mutex_t	*init_forks(int quantity)
{
	int				i;
	pthread_mutex_t	*forks;

	i = 0;
	forks = malloc(quantity * sizeof(pthread_mutex_t));
	if (!forks)
		return (NULL);
	while (i < quantity)
	{
		if (pthread_mutex_init(&forks[i], NULL))
		{
			while (i-- > 0)
				pthread_mutex_destroy(&forks[i]);
			free (forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

t_philo	*init_philo_data(t_elements *info, pthread_mutex_t *fork)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = malloc(info->nbr_of_philo * sizeof(t_philo));
	if (!philo)
		return (NULL);
	while (i < (int)info->nbr_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].count_meals = 0;
		philo[i].left_fork = &fork[i];
		philo[i].right_fork = &fork[(i + 1) % info->nbr_of_philo];
		if (pthread_mutex_init(&philo[i].print, NULL))
			return (NULL);
		philo[i].last_meal_t = get_time();
		philo[i].is_live = 1;
		philo[i].priority = 0;
		philo[i].info = info;
		i++;
	}
	return (philo);
}
