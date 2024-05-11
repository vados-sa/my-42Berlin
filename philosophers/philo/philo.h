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

typedef struct s_elements
{
	int				nbr_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nbr_of_meals;
	struct timeval	start_time;
}	t_elements;

typedef struct s_philo
{
	int				id;
	int				count_meals;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	print;
	pthread_mutex_t	state;
	struct timeval	last_meal_t;
	int				is_live;
	t_elements		*info;
}	t_philo;

/*init.c*/
void			parse_args(int ac, char *av[], t_elements *info);
t_elements		*init_struct(void);
pthread_mutex_t	*init_forks(int quantity);
t_philo			*init_philo_data(t_elements *info, pthread_mutex_t *fork);

/*utils.c*/
int				ft_custom_atoi(const char *s);

/*mem_manage.c*/
void			error_exit(t_elements *info);
void			cleanup(t_elements *info, pthread_mutex_t *fork, \
t_philo *philo);

/*simulation.c*/
void			simulation(t_philo *philo);

/*check.c*/
int				check_starvation(t_philo *philo);
int				check_state(t_philo *philo);
int				check_forks(t_philo *philo);

/*routine_utils.c*/
void	eat(t_philo *philo);
void	nap(t_philo *philo);
void	think(t_philo *philo);

#endif