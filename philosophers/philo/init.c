#include "philo.h"

static void	*init_forks(t_data *data);
static void	mutex_init(t_data *data);
static void	*philo_init(t_data *data);

void	parse_args(int ac, char *av[])
{
	if (ac != 5 && ac != 6)
	{
		printf("Wrong number of arguments!\n");
		exit(1);
	}
	if ((int)ft_custom_atoi(av[1]) <= 0 || (int)ft_custom_atoi(av[2]) <= 0 || 
		(int)ft_custom_atoi(av[3]) <= 0 || (int)ft_custom_atoi(av[4]) <= 0)
	{
		printf("All input values must be positive integers.\n");
		exit(1);
	}
	if (ac == 6) 
	{
		if ((int)ft_custom_atoi(av[5]) <= 0)
		{
			printf("'number_of_times_each_philosopher_must_eat' must be\
 a positive interger.\n");
			exit(1);
		}
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
	//data->life_status = ALIVE;
	data->nbr_of_philo = ft_custom_atoi(av[1]);
	data->time_to_die = ft_custom_atoi(av[2]);
	data->time_to_eat = ft_custom_atoi(av[3]);
	data->time_to_sleep = ft_custom_atoi(av[4]);
	//data->nbr_of_meals = -1; // check initial number !
	if (ac == 6)
		data->nbr_of_meals = ft_custom_atoi(av[5]);
	//printf("%d\n", (int)data->nbr_of_meals);
	//printf("nbr of meals: %d\n", (int)data->nbr_of_meals);
	init_forks(data);
	mutex_init(data);
	philo_init(data);
	return (data);
}

static void	*init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->nbr_of_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		cleanup(data, "Error initializing fork data!", EXIT_FAILURE);
	while (i < (int)data->nbr_of_philo)
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
	if(pthread_mutex_init(&data->state_mutex, NULL))
	{
		pthread_mutex_destroy(&data->print_mutex);
		cleanup(data, "Error initializing state mutex!", EXIT_FAILURE);
	}
	if(pthread_mutex_init(&data->meal_mutex, NULL))
	{
		pthread_mutex_destroy(&data->print_mutex);
		pthread_mutex_destroy(&data->state_mutex);
		cleanup(data, "Error initializing meal mutex!", EXIT_FAILURE);
	}
}

static void	*philo_init(t_data *data)
{
	int		i;

	i = -1;
	data->philo = malloc(data->nbr_of_philo * sizeof(t_philo));
	if (!data->philo)
		cleanup(data, "Error initializing philo data!", EXIT_FAILURE);
	while (++i < ((int)data->nbr_of_philo))
	{
		//printf("start init, philo[%d]\n", i);
		data->philo[i].id = i + 1;
		data->philo->count_meals = 0;
		data->philo[i].life_status = ALIVE;
		//data->philo[i].full = HUNGRY;
		//printf("philo[%d] is hungry? %d\n", i, data->philo[i].full);
		data->philo[i].nbr_of_meals = (int)data->nbr_of_meals;
		data->philo[i].time_to_die = data->time_to_die;
		data->philo[i].time_to_eat = data->time_to_eat;
		data->philo[i].time_to_sleep = data->time_to_sleep;
		data->philo[i].last_meal_t = data->start_time; // set updated time when threads are created
		data->philo->thread = 0;
		data->philo[i].left_fork = &data->forks[i];
		if (data->nbr_of_philo > 1)
			data->philo[i].right_fork = &data->forks[(i + 1) % data->nbr_of_philo];
		else
			data->philo[i].right_fork = 0;
		data->philo[i].data = data;
		//printf("finish init, philo[%d]\n", i);
	}
	return (NULL);
}
