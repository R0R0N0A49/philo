/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:38:19 by trebours          #+#    #+#             */
/*   Updated: 2024/07/10 09:15:16 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_dead(t_philo *src)
{
	pthread_mutex_lock(&src->data->m_dead);
	if (src->data->is_dead)
	{
		pthread_mutex_unlock(&src->data->m_dead);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&src->data->m_dead);
		return (0);
	}
}

void	is_dead(t_philo *args)
{
	if (!verif_dead(args))
	{
		pthread_mutex_lock(&args->data->m_dead);
		args->data->is_dead = 1;
		pthread_mutex_unlock(&args->data->m_dead);
		print_message(args, 0);
		return ;
	}
}

int	check_philo_status(t_philo *args, int i)
{
	if (i > 0|| verif_time_eat(args) || verif_dead(args))
	{
		is_dead(args);
		return (1);
	}
	return (0);
}

int	verif_philo(t_philo	*args)
{
	int i;

	i = 1;
	pthread_mutex_lock(&args->data->eat);
	if (args->data->is_eat >= args->data->nmb_of_philo)
		i = 0;
	pthread_mutex_unlock(&args->data->eat);
	return (i);
}

void	add_eat(t_philo *args)
{
	pthread_mutex_lock(&args->data->eat);
	if (args->nmb_eat == args->data->nmb_max_eat)
		args->data->is_eat++;
	pthread_mutex_unlock(&args->data->eat);
}
