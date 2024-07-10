/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:53:22 by trebours          #+#    #+#             */
/*   Updated: 2024/07/10 06:13:39 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_eat(t_philo *args)
{
	long	current_time;

	if (verif_time_eat(args))
		is_dead(args);
	if (verif_dead(args))
		return (1);
	define_last_eat(args);
	print_message(args, 2);
	current_time = get_timestamp(args->time->time_of_start);
	while (get_timestamp(args->time->time_of_start) - current_time
		< args->time->time_to_eat)
	{
		usleep(500);
		if (verif_time_eat(args))
			is_dead(args);
		if (verif_dead(args))
			return (1);
	}
	args->nmb_eat++;
	return (0);
}

int	is_sleep(t_philo *args)
{
	long	current_time;

	if (verif_time_eat(args))
		is_dead(args);
	if (verif_dead(args))
		return (1);
	print_message(args, 3);
	current_time = get_timestamp(args->time->time_of_start);
	while (get_timestamp(args->time->time_of_start) - current_time
		< args->time->time_to_sleep)
	{
		if (verif_time_eat(args))
			is_dead(args);
		if (verif_dead(args))
			return (1);
		ft_usleep(5);
	}
	return (0);
}
