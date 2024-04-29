#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <limits.h>

typedef struct s_elements
{
	int	nbr_of_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nbr_of_meals;
}	t_elements;

typedef struct s_philo
{
	int				id;
	int				count_meals;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_elements		*info;
}	t_philo;

/*init.c*/
void		parse_args(int ac, char *av[], t_elements *info);
t_elements	*init_struct(void);
t_philo		*init_philo(t_elements *info);

/*utils.c*/
int			ft_custom_atoi(const char *s);

/*mem_manage.c*/
void		error_exit(t_elements *info);


#endif