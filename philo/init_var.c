/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:31:43 by trebours          #+#    #+#             */
/*   Updated: 2024/07/10 10:53:54 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_src(t_philo *src, t_time *args)
{
	src->time = args;
	src->last_eat = get_time();
	src->next_forks = NULL;
	src->nmb_eat = 0;
	pthread_mutex_init(&src->current_forks, NULL);
}

t_time	*init_time(char **argv)
{
	t_time	*args;

	args = malloc(sizeof(t_time) * 1);
	if (!args)
		return (NULL);
	args->nmb_of_philo = ft_atoi(argv[1]);
	args->time_of_start = get_time();
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->is_dead = 0;
	if (argv[5])
		args->nmb_max_eat = ft_atoi(argv[5]);
	else
		args->nmb_max_eat = -1;
	pthread_mutex_init(&args->mutex, NULL);
	pthread_mutex_init(&args->print, NULL);
	return (args);
}

int	init_struct(t_philo **src, char **argv)
{
	t_philo	*current;
	t_time	*args;
	int		i;

	i = 0;
	args = init_time(argv);
	*src = ft_philonew(i + 1);
	current = *src;
	init_src(current, args);
	i++;
	while (i < ft_atoi(argv[1]))
	{
		current->next = ft_philonew(i + 1);
		if (!current->next)
			return (1);
		current->next_forks = current->next;
		current = current->next;
		init_src(current, args);
		i++;
	}
	current->next_forks = *src;
	return (0);
}
