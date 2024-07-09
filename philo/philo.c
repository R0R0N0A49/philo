/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:21:16 by trebours          #+#    #+#             */
/*   Updated: 2024/07/09 10:19:21 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_src(t_philo *src, t_time *args)
{
	src->time = args;
	src->last_eat = get_time();
	src->first = NULL;
	src->nmb_eat = 0;
	pthread_mutex_init(&src->mutex, NULL);
}

t_time	*init_time(char **argv)
{
	t_time *args;

	args = calloc(sizeof(t_time), 1);
	if (!args)
		return (NULL);
	args->time_of_start = get_time();
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		args->nmb_max_eat = ft_atoi(argv[5]);
	else
		args->nmb_max_eat = -1;
	pthread_mutex_init(&args->mutex, NULL);
	return (args);
}

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

int	init_struct(t_philo **src, char **argv)
{
	t_philo	*current;
	t_time	*args = NULL;
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
		current->first = current->next;
		current = current->next;
		init_src(current, args);
		i++;
	}
	return (0);
}

void	print_message(t_philo *src, int msg)
{
	long i;

	i = get_time();
	i -= src->time->time_of_start;
	pthread_mutex_unlock(&src->time->mutex);
	if (src->time->is_dead)
		printf("at %ld ms, philo %d\033[1;31m is dead\n\033[1;m", i, src->index);
	else if (msg == 1)
		printf("at %ld ms, philo %d\033[1;35m take a fork\n\033[1;m", i, src->index);
	else if (msg == 2)
		printf("at %ld ms, philo %d\033[1;36m is eating\n\033[1;m", i, src->index);
	else if (msg == 3)
		printf("at %ld ms, philo %d\033[1;33m is sleeping\n\033[1;m", i, src->index);
	else if (msg == 4)
		printf("at %ld ms, philo %d\033[1;32m is thinking\n\033[1;m", i, src->index);
	pthread_mutex_unlock(&src->time->mutex);
}

void	choise_fork(t_philo *src)
{
	int	i;
	pthread_mutex_lock(&src->mutex);
	print_message(src, 1);
	pthread_mutex_lock(&src->first->mutex);
	print_message(src, 1);
	i = is_eat(src);
	pthread_mutex_unlock(&src->mutex);
	pthread_mutex_unlock(&src->first->mutex);
	if (i) {
		is_dead(src);
		return;
	}
	is_sleep(src);
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

void	*philo(void *src)
{
	t_philo	*args;

	if (!src)
		return (NULL);
	args = src;
	if (args->index % 2 == 0) {
		usleep(100);
	}
	while (args->nmb_eat != args->time->nmb_max_eat)
	{
		pthread_mutex_lock(&args->time->mutex);
		if (args->time->is_dead)
		{
			pthread_mutex_unlock(&args->time->mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&args->time->mutex);
		if (verif_time_eat(src))
		{
			is_dead(src);
			return (NULL);
		}
		choise_fork(args);
		print_message(args, 4);
		pthread_mutex_lock(&args->time->mutex);
		if (args->time->is_dead) {
			pthread_mutex_unlock(&args->time->mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&args->time->mutex);
		if (verif_time_eat(src))
		{
			is_dead(src);
			return (NULL);
		}
	}
	return (NULL);
}

void	init_thread(t_philo *args, int n)
{
	pthread_t	*threads;
	t_philo		*current;
	int			i;

	threads = malloc(n * sizeof(pthread_t));
	if (!threads)
		return ;
	i = 0;
	current = args;
	if (n == 1)
	{
		is_dead(args);
		free(threads);
		return ;
	}
	while (i < n)
	{
		pthread_create(&threads[i], NULL, philo, current);
		if (!current->next)
			current->first = args;
		else
			current = current->next;
		i++;
	}
	i = 0;
	while (i < n)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	free(threads);
}

int	main(int argc, char **argv)
{
	t_philo	*args;

	args = NULL;
	if (parsing(argc, &argv[1]))
		return (1);
	if (init_struct(&args, argv))
		return (1);
	init_thread(args, ft_atoi(argv[1]));
	pthread_mutex_destroy(&args->time->mutex);
	free(args->time);
	ft_philoclear(&args, free);
	return (0);
}
