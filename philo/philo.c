/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:21:16 by trebours          #+#    #+#             */
/*   Updated: 2024/07/08 07:47:27 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_src(t_philo *src, char **argv)
{
	src->time_to_die = ft_atoi(argv[2]);
	src->time_to_eat = ft_atoi(argv[3]);
	src->time_to_sleep = ft_atoi(argv[4]);
	src->last_eat = 0;
	if (argv[5])
		src->nmb_of_eat = ft_atoi(argv[5]);
	else
		src->nmb_of_eat = 0;
}

int	init_struct(t_philo **src, char **argv)
{
	t_philo	*current;
	int		i;

	i = 0;
	*src = ft_philonew(i);
	current = *src;
	init_src(current, argv);
	i++;
	while (i < ft_atoi(argv[1]))
	{
		current->next = ft_philonew(i);
		if (!current->next)
			return (1);
		current = current->next;
		init_src(current, argv);
		i++;
	}
	return (0);
}

void	philo(t_philo *args)
{
	int				is_death;

	if (!args)
		return ;
	is_death = 1;
	printf("\033[1;39m\t\t\t The philo begins\n\033[1;m");
	while (is_death)
	{
		if (is_eat(args, &is_death))
			break ;
		if (!is_death)
			break ;
		if (is_sleep(args, &is_death))
			break ;
		if (is_death < 10 && is_death > 0)
			is_death++;
		else
			is_death = 0;
	}
	if (!is_death)
		printf("\033[6;35m\t\t\tOne philo is dead\n\033[1;m");
}

int	main(int argc, char **argv)
{
	t_philo	*args;

	args = NULL;
	if (parsing(argc, &argv[1]))
		return (1);
	if (init_struct(&args, argv))
		return (1);
	philo(args);
	ft_philoclear(&args, free);
	return (0);
}
