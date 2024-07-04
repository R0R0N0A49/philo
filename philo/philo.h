/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:21:56 by trebours          #+#    #+#             */
/*   Updated: 2024/07/04 14:51:26 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int nmb_of_eat;
	int index;
	struct s_philo *next;
}t_philo;

int		ft_number(char **src);
int		ft_atoi(const char *s1);
int		parsing(int argc, char **argv);
void	print_and_free(const int i, const char *c, void *src, void **tab);
void	ft_free_tab(void **tab);
int		ft_string_is_num(char *src);
t_philo	*ft_philonew(int i);
void	ft_philodelone(t_philo **list, void (*del)(void*));
void	ft_philoclear(t_philo **list, void (*del)(void*));

#endif