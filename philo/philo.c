/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:21:16 by trebours          #+#    #+#             */
/*   Updated: 2024/07/04 11:03:28 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*test_mudex(void *arg)
{
	t_philo	*src;

	src = arg;
	int		time = 5 * src->nmb_philo;
	usleep(time);
	printf("%d\n", src->nmb_philo);
	printf("%d\n", time);
	return ("fin du thread\n");
}

void	philo(t_philo *src, char **argv)
{
	// pthread_t	test[ft_atoi(argv[0])];
	int			t;

	t = 0;
	while (t < ft_atoi(argv[0]))
	{
		printf("%d\n", src->nmb_philo);
		// pthread_create(&test[t], NULL, test_mudex, src);
		t++;
	}
	t = 0;
	// while (t < ft_atoi(argv[0]))
	// {
		// pthread_join(test[t], NULL);
		// t++;
	// }
}

int	init_struct(t_philo *src, char **argv)
{
	int	i;

	i = 0;
	src = malloc(ft_atoi(argv[1]) * sizeof(t_philo));
	if (!src)
		return (1);
	while (i < ft_atoi(argv[1]))
	{
		src[i].nmb_philo = i;
		src[i].nmb_fork = ft_atoi(argv[0]);
		src[i].time_to_die = ft_atoi(argv[1]);
		src[i].time_to_eat = ft_atoi(argv[2]);
		src[i].time_to_sleep = ft_atoi(argv[3]);
		if (argv[4])
			src[i].nmb_of_eat = ft_atoi(argv[4]);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_philo	args;

	if (parsing(argc, &argv[1]))
		return (1);
	if (init_struct(&args, &argv[1]))
		return (1);
	philo(&args, &argv[1]);
	return (0);
}
