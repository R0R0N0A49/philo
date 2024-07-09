/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:53:22 by trebours          #+#    #+#             */
/*   Updated: 2024/07/09 10:18:48 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_eat(t_philo *args)
{
	define_last_eat(args);
	print_message(args, 2);
	usleep(args->time->time_to_eat * 1000);
	args->nmb_eat++;
	if (verif_dead(args))
		is_dead(args);
	if (verif_dead(args))
		return (1);
	return (0);
}

int	is_sleep(t_philo *args)
{
	int	i;

	i = 0;
	print_message(args, 3);
	while (i < args->time->time_to_sleep * 1000)
	{
		usleep(100);
		i += 100;
		if (verif_dead(args))
			is_dead(args);
		if (verif_dead(args))
			return (1);
	}
	return (0);
}
