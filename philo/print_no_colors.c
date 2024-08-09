/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:13:49 by trebours          #+#    #+#             */
/*   Updated: 2024/08/09 10:17:33 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_message(t_philo *src, int msg)
{
	long		i;
	static int	y = 0;

	i = get_time();
	i -= src->time->time_of_start;
	pthread_mutex_lock(&src->time->print);
	if (verif_dead(src) && !y)
	{
		printf("%ld %d died\n", i, src->index);
		y++;
	}
	else if (msg == 1)
		printf("%ld %d has taken a fork\n", i, src->index);
	else if (msg == 2)
		printf("%ld %d is eating\n", i, src->index);
	else if (msg == 3)
		printf("%ld %d is sleeping\n", i, src->index);
	else if (msg == 4)
		printf("%ld %d is thinking\n", i, src->index);
	pthread_mutex_unlock(&src->time->print);
}
