/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:53:22 by trebours          #+#    #+#             */
/*   Updated: 2024/07/08 07:54:48 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_eat(t_philo *args, int *is_death)
{
	printf("\033[3;32m\t\t\tThe philo %d eating\n\033[1;m", args->index);
	define_last_eat(args);
	usleep(args->time_to_eat * 1000);
	if (verif_time_eat(args))
		is_death[0] = 0;
	if (!is_death[0])
		return (1);
	return (0);
}

int	is_sleep(t_philo *args, int *is_death)
{
	int	i;

	printf("\033[1;36m\t\t      The philo %d is sleeping\n\033[1;m",
		args->index);
	i = 0;
	while (i < args->time_to_sleep * 1000)
	{
		usleep(100);
		i += 100;
		if (verif_time_eat(args))
			is_death[0] = 0;
		if (!is_death[0])
			return (1);
	}
	return (0);
}
