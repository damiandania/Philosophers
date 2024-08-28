/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:22:00 by dania             #+#    #+#             */
/*   Updated: 2023/10/11 17:09:54 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
//____________________________________________________________________
//_____________________________I͟N͟C͟L͟U͟D͟E͟S͟_______________________________

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdbool.h>
//____________________________________________________________________
//_____________________________M͟A͟C͟R͟O͟S͟_________________________________

# define MAX_PHILOS 250

# define ERR_USAGE "usage: ./philo <num_philo> <time to die> <time to eat>\
 <time to sleep> [# times each philosopher must eat]\n"
# define ERR_ARGS "error: invalid arguments\n"
# define ERR_INT "error: arguments must be only numbers\n"
# define ERR_EMPTY "error: argument empty\n"
# define ERR_MAX_PHILOS "error: more than 250 philos\n"
# define ERR_NEG "error: negative argument\n"
# define ERR_MAX_INT "error: argument higher than max int\n"
# define ERR_MALLOC "error: memory\n"
# define ERR_MUTEX "error: mutex\n"
# define ERR_THREAD "error: thread\n"
//____________________________________________________________________
//_____________________________S͟T͟R͟U͟C͟T͟U͟R͟E͟______________________________

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	id;
	unsigned int	eat_counter;
	t_data			*data;
	unsigned int	fork1;
	unsigned int	fork2;
	pthread_mutex_t	eat_time_locker;
	time_t			time_last_meal;

}		t_philo;

typedef struct s_data
{
	unsigned int	num_philo;
	unsigned int	time_die;
	unsigned int	time_eat;
	unsigned int	time_sleep;
	int				num_eat;
	pthread_mutex_t	*fork_locker;
	pthread_mutex_t	print_loker;
	pthread_mutex_t	stop_locker;
	pthread_t		kill_thread_locker;
	t_philo			**philo;
	time_t			start_time;
	bool			stop;
}		t_data;

typedef enum s_sta
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	FORK1 = 4,
	FORK2 = 5
}		t_sta;
//____________________________________________________________________
//_____________________________F͟U͟N͟T͟I͟O͟N͟S͟_______________________________

//	PARSING
bool	check_input(int ac, char **av);
int		ft_atoi(char *str);

//	UTILS
int		ft_strlen(const char *s);
time_t	get_time(void);
void	delay_time(time_t start_time);
void	*free_data(t_data *data);

//	INIT
t_data	*init_data(int ac, char **av);

//	THREAD
bool	start_thread(t_data *data);
void	stop_thread(t_data *data);
void	*kill_thread(void *data);

//	ROUTINE
void	*philo_routine(void *data);
void	time_to_sleep(t_data *data, time_t sleep_time);

//	PRINT
void	show_status(t_philo *philo, t_sta status);
int		exit_msg(char *msg, int exit_code);
void	*exit_null(char *msg, t_data *data);

//	STOP
bool	check_stop(t_data *data);
void	destroy_mutex(t_data *data);
void	stop_status(t_data *data, bool status);
bool	finished(t_data *data);

#endif
