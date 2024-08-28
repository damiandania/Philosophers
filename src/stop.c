/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:37:22 by dania             #+#    #+#             */
/*   Updated: 2023/10/11 17:15:16 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_stop(t_data *data)
{
	bool	ret;

	ret = false;
	pthread_mutex_lock(&data->stop_locker);
	if (data->stop == true)
		ret = true;
	pthread_mutex_unlock(&data->stop_locker);
	return (ret);
}

void	destroy_mutex(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->fork_locker[i]);
		pthread_mutex_destroy(&data->philo[i]->eat_time_locker);
		i++;
	}
	pthread_mutex_destroy(&data->print_loker);
	pthread_mutex_destroy(&data->stop_locker);
}

void	stop_status(t_data *data, bool status)
{
	pthread_mutex_lock(&data->stop_locker);
	data->stop = status;
	pthread_mutex_unlock(&data->stop_locker);
}

static bool	kill_philo(t_philo *philo)
{
	time_t	time;

	time = get_time();
	if ((time - philo->time_last_meal) >= philo->data->time_die)
	{
		stop_status(philo->data, true);
		show_status(philo, DIED);
		pthread_mutex_unlock(&philo->eat_time_locker);
		return (true);
	}
	return (false);
}

bool	finished(t_data *data)
{
	unsigned int	i;
	bool			finished;

	finished = true;
	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->philo[i]->eat_time_locker);
		if (kill_philo(data->philo[i]))
			return (true);
		if (data->num_eat != -1)
			if (data->philo[i]->eat_counter < (unsigned int)data->num_eat)
				finished = false;
		pthread_mutex_unlock(&data->philo[i]->eat_time_locker);
		i++;
	}
	if (data->num_eat != -1 && finished == true)
	{
		stop_status(data, true);
		return (true);
	}
	return (false);
}
