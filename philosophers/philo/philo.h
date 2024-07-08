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

typedef struct s_elements
{
	uint64_t	nbr_of_philo;
	uint64_t	time_to_die;
	uint64_t	time_to_eat;
	uint64_t	time_to_sleep;
	uint64_t	nbr_of_meals;
	uint64_t	start_time;
}	t_elements;

typedef struct s_philo
{
	int				id;
	int				count_meals;
	int				life_status;
	uint64_t		last_meal_t;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	state_mutex;
	pthread_mutex_t	meal_mutex;
	t_elements		*info;
}	t_philo;

/*init.c*/
void			parse_args(int ac, char *av[], t_elements *info);
t_elements		*init_struct(void);
pthread_mutex_t	*init_forks(int quantity);
t_philo			*init_philo_data(t_elements *info, pthread_mutex_t *fork);

/*utils.c*/
uint64_t		ft_custom_atoi(const char *s);
uint64_t		get_time(void);
void			precise_usleep(uint64_t usec);
void			print_status(t_philo *philo, char *s);

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
int				check_meals(t_philo *philo);

/*monitor_util.c*/
void			announce_death(t_philo *philo);
int				track_meals(t_philo *philo, uint64_t total_meals);

/*routine_utils.c*/
int				eat(t_philo *philo);
int				nap(t_philo *philo);
int				think(t_philo *philo);

#endif