/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_dead.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:38:19 by trebours          #+#    #+#             */
/*   Updated: 2024/07/10 06:39:27 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	verif_dead(t_philo *src)
{
	pthread_mutex_lock(&src->time->mutex);
	if (src->time->is_dead == 1)
	{
		pthread_mutex_unlock(&src->time->mutex);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&src->time->mutex);
		return (0);
	}
}

void	is_dead(t_philo *args)
{
	pthread_mutex_lock(&args->time->mutex);
	if (!args->time->is_dead)
	{
		args->time->is_dead = 1;
		print_message(args, 0);
	}
	pthread_mutex_unlock(&args->time->mutex);
}
