/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:53:22 by trebours          #+#    #+#             */
/*   Updated: 2024/08/16 09:52:24 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_eat(t_philo *args)
{
	long	current_time;

	if (!verif_philo(args))
		return (-1);
	if (check_philo_status(args, 0))
		return (1);
	define_last_eat(args);
	print_message(args, 2);
	current_time = get_timestamp(args->data->time_of_start);
	while (get_timestamp(args->data->time_of_start) - current_time
		< args->data->time_to_eat)
	{
		ft_usleep(1);
		if (!verif_philo(args))
			return (-1);
		if (check_philo_status(args, 0))
			return (1);
	}
	args->nmb_eat++;
	if (args->nmb_eat == args->data->nmb_max_eat)
		add_eat(args);
	if (check_philo_status(args, 0))
		return (1);
	return (0);
}

int	is_sleep(t_philo *args)
{
	long	current_time;

	if (!verif_philo(args))
		return (-1);
	print_message(args, 3);
	current_time = get_timestamp(args->data->time_of_start);
	while (get_timestamp(args->data->time_of_start) - current_time
		< args->data->time_to_sleep)
	{
		ft_usleep(1);
		if (!verif_philo(args))
			return (-1);
		if (check_philo_status(args, 0))
			return (1);
	}
	if (check_philo_status(args, 0))
		return (1);
	print_message(args, 4);
	return (0);
}
