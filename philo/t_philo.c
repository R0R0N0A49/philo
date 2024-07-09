/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 14:39:06 by trebours          #+#    #+#             */
/*   Updated: 2024/07/09 04:54:16 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_philonew(int i)
{
	t_philo	*new_arg;

	new_arg = malloc(1 * sizeof(t_philo));
	if (!new_arg)
		return (NULL);
	new_arg->index = i;
	new_arg->next = NULL;
	return (new_arg);
}

void	ft_philodelone(t_philo **list, void (*del)(void*))
{
	if (!list || !del || !*list)
		return ;
	pthread_mutex_destroy(&list[0]->mutex);
	del(*list);
	*list = NULL;
}

void	ft_philoclear(t_philo **list, void (*del)(void*))
{
	if (!list || !del || !*list)
		return ;
	if (((*list)->next) != NULL)
		ft_philoclear(&(*list)->next, del);
	ft_philodelone(list, del);
}
