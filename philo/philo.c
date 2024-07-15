/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:21:16 by trebours          #+#    #+#             */
/*   Updated: 2024/07/15 05:11:51 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_philo_status(t_philo *args, int i)
{
	if (i || verif_time_eat(args) || verif_dead(args))
	{
		is_dead(args);
		return (1);
	}
	return (0);
}

void	choise_fork(t_philo *src)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (check_philo_status(src, 0))
			return ;
		pthread_mutex_lock(&src->current_forks);
		if (src->forks)
		{
			print_message(src, 1);
			src->forks = 0;
			i++;
		}
		pthread_mutex_unlock(&src->current_forks);
		pthread_mutex_lock(&src->next_forks->current_forks);
		if (src->next_forks->forks)
		{
			print_message(src, 1);
			src->next_forks->forks = 0;
			i++;
		}
		pthread_mutex_unlock(&src->next_forks->current_forks);
	}
}

void	wait_finish(t_philo *src)
{
	pthread_mutex_lock(&src->time->mutex);
	src->time->nmb_of_philo--;
	pthread_mutex_unlock(&src->time->mutex);
	while (src->time->nmb_of_philo)
	{
		if (check_philo_status(src, 0))
			return ;
		ft_usleep(3);
	}
}

void	*loop_philo(t_philo *args)
{
	int	i;

	i = 0;
	while (args->nmb_eat != args->time->nmb_max_eat)
	{
		choise_fork(args);
		if (check_philo_status(args, i))
			return (NULL);
		i = is_eat(args);
		reset_forks(args);
		if (check_philo_status(args, i))
			return (NULL);
		if (args->nmb_eat == args->time->nmb_max_eat)
			print_message(args, 4);
		else
			i = is_sleep(args);
		if (check_philo_status(args, i))
			return (NULL);
	}
	return (NULL);
}

void	*philo(void *src)
{
	t_philo	*args;

	if (!src)
		return (NULL);
	args = src;
	if (args->index % 2 == 0 || (args->next == NULL && args->index % 2))
	{
		print_message(args, 4);
		ft_usleep(1);
	}
	loop_philo(args);
	wait_finish(args);
	return (NULL);
}
