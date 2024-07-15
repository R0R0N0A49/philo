/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:30:24 by trebours          #+#    #+#             */
/*   Updated: 2024/07/08 07:32:46 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	reset_forks(t_philo *src)
{
	pthread_mutex_lock(&src->current_forks);
	src->forks = 1;
	pthread_mutex_unlock(&src->current_forks);
	pthread_mutex_lock(&src->next_forks->current_forks);
	src->next_forks->forks = 1;
	pthread_mutex_unlock(&src->next_forks->current_forks);
}

void	ft_free_tab(void **tab)
{
	int	i;

	if (tab && tab[0])
	{
		i = 0;
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
	}
	if (tab)
		free(tab);
}

int	ft_atoi(const char *s1)
{
	int	i;
	int	y;
	int	rsl;

	i = 0;
	y = 1;
	rsl = 0;
	if (!s1[i])
		return (rsl);
	while (s1[i] == 32 || (s1[i] >= '\t' && s1[i] <= '\r'))
		i++;
	if (s1[i] == '-' || s1[i] == '+')
	{
		if (s1[i] == '-')
			y = -1;
		i++;
	}
	while (s1[i] >= '0' && s1[i] <= '9')
	{
		rsl = rsl * 10 + (s1[i] - '0');
		i++;
	}
	return (rsl * y);
}

int	ft_string_is_num(char *src)
{
	int	i;

	i = 0;
	while (src[i] >= '0' && src[i] <= '9')
		i++;
	if (!src[i])
		return (0);
	return (1);
}
