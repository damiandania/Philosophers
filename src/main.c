/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:27:52 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/11 16:28:21 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	data = NULL;
	if (ac != 5 && ac != 6)
		return (exit_msg(ERR_USAGE, EXIT_FAILURE));
	if (!check_input(ac, av))
		return (EXIT_FAILURE);
	data = init_data(ac, av);
	if (!data)
		return (EXIT_FAILURE);
	if (!start_thread(data))
	{
		free_data(data);
		return (exit_msg(ERR_THREAD, EXIT_FAILURE));
	}
	stop_thread(data);
	return (0);
}
