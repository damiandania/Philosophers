/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 23:08:14 by dania             #+#    #+#             */
/*   Updated: 2023/10/11 16:31:37 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		++i;
	return (i);
}

time_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	delay_time(time_t start_time)
{
	while (get_time() < start_time)
		continue ;
}

void	*free_data(t_data *data)
{
	unsigned int	i;

	if (!data)
		return (NULL);
	if (data->fork_locker != NULL)
		free(data->fork_locker);
	if (data->philo != NULL)
	{
		i = 0;
		while (i < data->num_philo)
		{
			if (data->philo[i] != NULL)
				free(data->philo[i]);
			i++;
		}
		free(data->philo);
	}
	free(data);
	return (NULL);
}
