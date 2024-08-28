/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:28:05 by dania             #+#    #+#             */
/*   Updated: 2023/10/11 18:09:40 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_locker[philo->fork1]);
	show_status(philo, FORK1);
	pthread_mutex_lock(&philo->data->fork_locker[philo->fork2]);
	show_status(philo, FORK2);
	show_status(philo, EATING);
	pthread_mutex_lock(&philo->eat_time_locker);
	philo->time_last_meal = get_time();
	pthread_mutex_unlock(&philo->eat_time_locker);
	time_to_sleep(philo->data, philo->data->time_eat);
	if (check_stop(philo->data) == false)
	{
		pthread_mutex_lock(&philo->eat_time_locker);
		philo->eat_counter++;
		pthread_mutex_unlock(&philo->eat_time_locker);
		show_status(philo, SLEEPING);
	}
	pthread_mutex_unlock(&philo->data->fork_locker[philo->fork1]);
	pthread_mutex_unlock(&philo->data->fork_locker[philo->fork2]);
	time_to_sleep(philo->data, philo->data->time_sleep);
}

static void	think_routine(t_philo *philo, bool status)
{
	time_t	think_time;

	pthread_mutex_lock(&philo->eat_time_locker);
	think_time = (philo->data->time_die - (get_time()
				- philo->time_last_meal) - philo->data->time_eat) / 2;
	pthread_mutex_unlock(&philo->eat_time_locker);
	if (think_time < 0)
		think_time = 0;
	if (think_time == 0 && status == true)
		think_time = 1;
	if (think_time > 600)
		think_time = 200;
	if (status == false)
		show_status(philo, THINKING);
	time_to_sleep(philo->data, think_time);
}

static void	*solo_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->fork_locker[philo->fork1]);
	show_status(philo, FORK1);
	time_to_sleep(philo->data, philo->data->time_die);
	philo->data->stop = true;
	show_status(philo, DIED);
	pthread_mutex_unlock(&philo->data->fork_locker[philo->fork1]);
	return (NULL);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->data->num_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->eat_time_locker);
	philo->time_last_meal = philo->data->start_time;
	pthread_mutex_unlock(&philo->eat_time_locker);
	delay_time(philo->data->start_time);
	if (philo->data->time_die == 0)
		return (NULL);
	if (philo->data->num_philo == 1)
		return (solo_routine(philo));
	else if (philo->id % 2)
		think_routine(philo, true);
	while (check_stop(philo->data) == false)
	{
		eat_routine(philo);
		think_routine(philo, false);
	}
	return (NULL);
}

void	time_to_sleep(t_data *data, time_t sleep_time)
{
	time_t	wake_up;

	(void)data;
	wake_up = get_time() + sleep_time;
	while (get_time() < wake_up)
	{
		if (check_stop(data) == true)
			return ;
		usleep(100);
	}
}
