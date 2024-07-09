/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 07:51:25 by trebours          #+#    #+#             */
/*   Updated: 2024/07/09 06:55:19 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	define_last_eat(t_philo *args)
{
	struct timeval	time;
	long			time_of_eat;

	gettimeofday(&time, NULL);
	time_of_eat = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	args->last_eat = time_of_eat;
}

int	verif_time_eat(t_philo *args)
{
	struct timeval	time;
	long			current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	if (current_time - args->last_eat >= args->time->time_to_die)
		return (1);
	return (0);
}

long get_time()
{
	struct timeval	time;
	long			current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time);
}