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

void	choise_fork(t_philo *src)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (check_philo_status(src, 0) || !verif_philo(src))
			return ;
		pthread_mutex_lock(&src->current_forks);
		if (src->forks && verif_philo(src))
		{
			print_message(src, 1);
			src->forks = 0;
			i++;
		}
		pthread_mutex_unlock(&src->current_forks);
		pthread_mutex_lock(&src->next_forks->current_forks);
		if (src->next_forks->forks && verif_philo(src))
		{
			print_message(src, 1);
			src->next_forks->forks = 0;
			i++;
		}
		pthread_mutex_unlock(&src->next_forks->current_forks);
	}
}

void	*loop_philo(t_philo *args)
{
	int	i;

	i = 0;
	while (verif_philo(args))
	{
		choise_fork(args);
		if (check_philo_status(args, i))
			return (NULL);
		i = is_eat(args);
		reset_forks(args);
		if (check_philo_status(args, i))
			return (NULL);
		if (!verif_philo(args) || i == -1)
			break ;
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
		ft_usleep(5);
	}
	loop_philo(args);
	return (NULL);
}
