/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vados-sa <vados-sa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:45:12 by vados-sa          #+#    #+#             */
/*   Updated: 2024/10/14 15:45:14 by vados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>
# include <stdint.h>
# include <inttypes.h>

# define DEAD 1
# define ALIVE 0
# define FULL 1
# define HUNGRY 0

typedef struct s_philo	t_philo;

typedef struct s_data
{
	uint64_t		nbr_of_philo;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		nbr_of_meals;
	uint64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex; 
	pthread_mutex_t	state_mutex;
	pthread_mutex_t	meal_mutex;
	t_philo			*philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				count_meals;
	int				life_status;
	int				full;
	int				nbr_of_meals;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	uint64_t		last_meal_t;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

/*init.c*/
t_data		*init_data(int ac, char *av[]);

/*utils.c*/
void		print_status(t_philo *philo, char *s);
//void		precise_usleep(uint64_t usec);
uint64_t	get_time(void);
uint64_t	ft_custom_atoi(const char *s);

/*mem_manage.c*/
void		print_error_exit(char *message, int exit_code);
void		cleanup(t_data *data, char *message, int exit_code);

/*simulation.c*/
void		simulation(t_data *data);

/*monitor.c*/
void		*monitor(t_data *data);

/*routine_utils.c*/
int			eat(t_philo *philo);
int			nap(t_philo *philo);
int			think(t_philo *philo);

#endif