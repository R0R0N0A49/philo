/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:21:56 by trebours          #+#    #+#             */
/*   Updated: 2024/07/04 11:41:23 by trebours         ###   ########.fr       */
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
	int				i;
	int				nmb_fork;
	int				nmb_philo;
	int				nmb_of_eat;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	test_l;
}t_philo;

int		ft_number(char **src);
int		ft_atoi(const char *s1);
int		parsing(int argc, char **argv);
void    print_and_free(const int i, const char c, void *src, void **tab);
void    ft_free_tab(void **tab);


#endif