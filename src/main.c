/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dania <dania@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 21:25:05 by dania             #+#    #+#             */
/*   Updated: 2023/09/03 23:24:35 by dania            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h" 

static int	check_args(t_data *data, int arc, char **arg)
{
	int	i;

	i = 1;
	while (i != arc)
	{
		if ( || ft_atoi(arg[i]) < 0);
			return (0);
		i++;
	}
	
	if (!num || num < 0 || (pos == 1 && num > 200) || (pos == 2 && num < 60)
		|| (pos == 3 && num < 60) || (pos == 4 && num < 60))
	{
		free(data);
		write(1, "argument invalid\n", 17);
		printf("error: %d", EXIT_FAILURE);
		return (0);
	}
	if (pos == 1)
		data->num_of_philo = num;
	if (pos == 2)
		data->time_die = num;
	if (pos == 3)
		data->time_eat = num;
	if (pos == 4)
		data->time_sleep = num;
	if (pos == 5)
		data->num_of_eat = num;
	return (1);
}

int	main(int arc, char ** arg)
{
	t_data	data;

	if (arc != 5 && arc != 6)
		return (exit_error(ERR_USAGE));
		
	if (!check_args(&data, arc, arg))
		return (exit_error("argument invalid\n"));

			
	// if(start_simulation(data) != 0)
	// 	return (EXIT_FAILURE);
	printf("philo num: %d\n", data.num_of_eat);
	printf("time die: %d\n", data.time_die);
	printf("time eat: %d\n", data.time_eat);
	printf("time sleep: %d\n", data.time_sleep);
	printf("philo eats: %d\n", data.num_of_eat);
	return (0);
}