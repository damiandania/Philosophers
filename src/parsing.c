/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddania-c <ddania-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:39:08 by ddania-c          #+#    #+#             */
/*   Updated: 2023/10/11 16:31:18 by ddania-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	its_digit(char *str)
{
	if (*str == '-')
		exit (exit_msg(ERR_NEG, false));
	if (*str == '\0')
		exit (exit_msg(ERR_EMPTY, false));
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

int	ft_atoi(char *str)
{
	unsigned long int	nb;

	nb = 0;
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	if (nb > INT_MAX)
		return (-1);
	return ((int)nb);
}

bool	check_input(int ac, char **av)
{
	int	i;
	int	nb;

	i = 1;
	while (i != ac)
	{
		if (!its_digit(av[i]))
			return (exit_msg(ERR_INT, false));
		nb = ft_atoi(av[i]);
		if (i == 1 && (nb <= 0 || nb > 250))
			return (exit_msg(ERR_MAX_PHILOS, false));
		if (i != 1 && nb == -1)
			return (exit_msg(ERR_MAX_INT, false));
		i++;
	}
	return (true);
}
