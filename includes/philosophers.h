/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 17:22:00 by dania             #+#    #+#             */
/*   Updated: 2023/09/03 23:16:04 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <stdlib.h>

# define ERR_USAGE "Usage: ./philo <# philosophers> <time to die> <time to eat>\
 <time to sleep> [# times each philosopher must eat]\n"

typedef struct s_philo
{
	int		eat_counter;
	int		pos;
}		t_philo;


typedef struct s_data
{
	int		num_of_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		num_of_eat;
	t_philo	*philo;
}		t_data;

int	ft_atoi(const char *str);




#endif