/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:21:16 by trebours          #+#    #+#             */
/*   Updated: 2024/07/10 07:15:48 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	choise_fork(t_philo *src)
{
	int i;

	i = 0;
	if (src->nmb_eat)
		print_message(src, 4);
	while (i < 2)
	{
		pthread_mutex_lock(&src->mutex);
		if (src->forks)
		{
			print_message(src, 1);
			src->forks = 0;
			i++;
		}
		pthread_mutex_unlock(&src->mutex);
		if (verif_time_eat(src) || verif_dead(src))
		{
			is_dead(src);
			return;
		}
		pthread_mutex_lock(&src->first->mutex);
		if (src->first->forks)
		{
			print_message(src, 1);
			src->first->forks = 0;
			i++;
		}
		pthread_mutex_unlock(&src->first->mutex);
	}
}

void	reset_forks(t_philo *src)
{
	pthread_mutex_lock(&src->mutex);
	if (!src->forks)
		src->forks = 1;
	pthread_mutex_unlock(&src->mutex);
	pthread_mutex_lock(&src->first->mutex);
	if (!src->first->forks)
		src->first->forks = 1;
	pthread_mutex_unlock(&src->first->mutex);
}

void	*philo(void *src)
{
	t_philo	*args;
	int i;

	if (!src)
		return (NULL);
	args = src;
	if (args->index % 2 == 0) {
		usleep(50);
	}
	i = 0;
	while (args->nmb_eat != args->time->nmb_max_eat)
	{
		if (i || verif_time_eat(args) || verif_dead(args))
		{
			is_dead(args);
			return (NULL);
		}
		choise_fork(args);
		if (verif_time_eat(args) || verif_dead(args))
		{
			is_dead(args);
			return (NULL);
		}
		i = is_eat(args);
		reset_forks(args);
		if (i || verif_time_eat(args) || verif_dead(args))
		{
			is_dead(args);
			return (NULL);
		}
		i = is_sleep(args);
	}
	return (NULL);
}
