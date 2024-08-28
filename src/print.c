/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:41:02 by dania             #+#    #+#             */
/*   Updated: 2023/10/11 17:19:35 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_msg(char *msg, int exit_code)
{
	write(1, msg, ft_strlen(msg));
	return (exit_code);
}

void	*exit_null(char *msg, t_data *data)
{
	free_data(data);
	write(1, msg, ft_strlen(msg));
	return (NULL);
}

static void	print_status(t_philo *philo, char *status)
{
	printf("%ld %d %s\n", get_time() - philo->data->start_time,
		philo->id + 1, status);
}

void	show_status(t_philo *philo, t_sta status)
{
	pthread_mutex_lock(&philo->data->print_loker);
	if (check_stop(philo->data) == true)
	{
		if (status == DIED)
			print_status(philo, "died");
		pthread_mutex_unlock(&philo->data->print_loker);
		return ;
	}
	if (status == SLEEPING)
		print_status(philo, "is sleeping");
	else if (status == THINKING)
		print_status(philo, "is thinking");
	else if (status == EATING)
		print_status(philo, "is eating");
	else if (status == FORK1 || status == FORK2)
		print_status(philo, "has taken a fork");
	pthread_mutex_unlock(&philo->data->print_loker);
}
