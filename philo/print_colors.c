/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 10:13:40 by trebours          #+#    #+#             */
/*   Updated: 2024/08/09 10:13:44 by trebours         ###   ########.fr       */
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
		printf("\033[1;34m%ld\033[1;0m \033[1;34m%d\033[1;m "
			"\033[1;31m died\n\033[1;m", i, src->index);
		y++;
	}
	else if (msg == 1)
		printf("\033[1;34m%ld\033[1;0m \033[1;34m%d\033[1;0m "
			"\033[1;35m has taken a fork\n\033[1;m", i, src->index);
	else if (msg == 2)
		printf("\033[1;34m%ld\033[1;0m \033[1;34m%d\033[1;0m "
			"\033[1;36m is eating\n\033[1;m", i, src->index);
	else if (msg == 3)
		printf("\033[1;34m%ld\033[1;0m \033[1;34m%d\033[1;0m "
			"\033[1;33m is sleeping\n\033[1;m", i, src->index);
	else if (msg == 4)
		printf("\033[1;34m%ld\033[1;0m \033[1;34m%d\033[1;0m "
			"\033[1;32m is thinking\n\033[1;m", i, src->index);
	pthread_mutex_unlock(&src->time->print);
}
