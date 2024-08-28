/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:44:27 by dania             #+#    #+#             */
/*   Updated: 2023/10/11 16:25:27 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	start_thread(t_data *data)
{
	unsigned int	i;

	i = 0;
	data->start_time = get_time() + (data->num_philo * 2 * 10);
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philo[i]->thread, NULL,
				&philo_routine, data->philo[i]) != 0)
			return (false);
		i++;
	}
	if (data->num_philo > 1)
	{
		if (pthread_create(&data->kill_thread_locker, NULL,
				&kill_thread, data) != 0)
			return (false);
	}
	return (true);
}

void	stop_thread(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philo[i]->thread, NULL);
		i++;
	}
	if (data->num_philo > 1)
		pthread_join(data->kill_thread_locker, NULL);
	destroy_mutex(data);
	free_data(data);
}

void	*kill_thread(void *data)
{
	t_data	*temp;

	temp = (t_data *)data;
	if (temp->num_eat == 0)
		return (NULL);
	stop_status(temp, false);
	delay_time(temp->start_time);
	while (true)
	{
		if (finished(temp) == true)
			return (NULL);
		usleep(1000);
	}
	return (NULL);
}
