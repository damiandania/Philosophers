/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:45:12 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/11 16:26:40 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*init_fork(t_data *data)
{
	pthread_mutex_t	*fork;
	unsigned int	i;

	fork = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!fork)
		return (exit_null(ERR_MUTEX, data));
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&fork[i], NULL) != 0)
			return (exit_null(ERR_MUTEX, data));
		i++;
	}
	return (fork);
}

static bool	init_mutex(t_data *data)
{
	data->fork_locker = init_fork(data);
	if (!data->fork_locker)
		return (false);
	if (pthread_mutex_init(&data->stop_locker, 0) != 0)
		return (false);
	if (pthread_mutex_init(&data->print_loker, 0) != 0)
		return (false);
	return (true);
}

static void	take_a_fork(t_philo *philo)
{
	philo->fork1 = philo->id;
	philo->fork2 = (philo->id + 1) % philo->data->num_philo;
	if (philo->id % 2)
	{
		philo->fork1 = (philo->id + 1) % philo->data->num_philo;
		philo->fork2 = philo->id;
	}
}

static t_philo	**init_philos(t_data *data)
{
	t_philo			**philo;
	unsigned int	i;

	i = 0;
	philo = malloc(sizeof(t_philo) * data->num_philo);
	if (!philo)
		return (exit_null(ERR_MALLOC, data));
	while (i < data->num_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		if (!philo[i])
			return (exit_null(ERR_MALLOC, data));
		if (pthread_mutex_init(&philo[i]->eat_time_locker, NULL) != 0)
			return (exit_null(ERR_MUTEX, data));
		philo[i]->data = data;
		philo[i]->id = i;
		philo[i]->eat_counter = 0;
		take_a_fork(philo[i]);
		i++;
	}
	return (philo);
}

t_data	*init_data(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
		exit (exit_msg(ERR_MALLOC, 0));
	data->num_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->num_eat = -1;
	if (ac == 6)
		data->num_eat = ft_atoi(av[5]);
	data->philo = init_philos(data);
	if (!init_mutex(data))
		return (exit_null(ERR_MUTEX, NULL));
	data->stop = false;
	return (data);
}
