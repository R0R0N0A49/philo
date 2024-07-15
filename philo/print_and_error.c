/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_and_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 09:37:58 by trebours          #+#    #+#             */
/*   Updated: 2024/07/10 10:05:24 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	choice_msg(const int i, const char *c)
{
	if (i == 0)
		printf("to less or more argument\n");
	if (i == 1)
	{
		printf("\'%s\' is not a number\n", c);
	}
	if (i == 2)
		printf("values must be greater than 0\n");
}

static void	ft_free(void *src, void **tab)
{
	if (src)
		free(src);
	if (tab && tab[0])
		ft_free_tab(tab);
}

void	print_and_free(const int i, const char *c, void *src, void **tab)
{
	choice_msg(i, c);
	ft_free(src, tab);
}

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
