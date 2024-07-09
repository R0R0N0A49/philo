/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:21:56 by trebours          #+#    #+#             */
/*   Updated: 2024/07/09 09:54:26 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_time
{
	long time_of_start;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	pthread_mutex_t	mutex;
	int	is_dead;
	int	nmb_max_eat;
} t_time;

typedef struct s_philo
{
	t_time			*time;
	int 			nmb_eat;
	int				index;
	long int		last_eat;
	struct s_philo	*first;
	pthread_mutex_t	mutex;
	struct s_philo	*next;
}	t_philo;

int		ft_number(char **src);
int		ft_atoi(const char *s1);
int		parsing(int argc, char **argv);
void	print_and_free(const int i, const char *c, void *src, void **tab);
void	ft_free_tab(void **tab);
int		ft_string_is_num(char *src);
int		verif_time_eat(t_philo *args);
void	define_last_eat(t_philo *args);
t_philo	*ft_philonew(int i);
void	ft_philodelone(t_philo **list, void (*del)(void*));
void	ft_philoclear(t_philo **list, void (*del)(void*));
int		is_eat(t_philo *args);
int		is_sleep(t_philo *args);
void	print_message(t_philo *src, int msg);
long	get_time();
void	is_dead(t_philo *args);
int		verif_dead(t_philo *src);

#endif