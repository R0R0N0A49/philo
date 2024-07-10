/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 06:41:13 by trebours          #+#    #+#             */
/*   Updated: 2024/07/10 06:49:40 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_thread(pthread_t *threads, t_philo *args, int n)
{
	int		i;
	t_philo	*current;

	i = 0;
	current = args;
	while (i < n)
	{
		pthread_create(&threads[i], NULL, philo, current);
		if (current->next)
			current = current->next;
		i++;
	}
}

void	end_threads(pthread_t *threads, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	init_thread(t_philo *args, int n)
{
	pthread_t	*threads;

	if (n == 1)
	{
		is_dead(args);
		return ;
	}
	threads = malloc(n * sizeof(pthread_t));
	if (!threads)
		return ;
	start_thread(threads, args, n);
	end_threads(threads, n);
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
