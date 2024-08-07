/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 13:21:56 by trebours          #+#    #+#             */
/*   Updated: 2024/07/15 05:07:10 by trebours         ###   ########.fr       */
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
	long			time_of_start;
	int				nmb_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	pthread_mutex_t	mutex;
	pthread_mutex_t	print;
	int				is_dead;
	int				nmb_max_eat;
}	t_time;

typedef struct s_philo
{
	t_time			*time;
	int				nmb_eat;
	int				index;
	long int		last_eat;
	int				forks;
	struct s_philo	*next_forks;
	pthread_mutex_t	current_forks;
	struct s_philo	*next;
}	t_philo;

int			ft_number(char **src);
int			ft_atoi(const char *s1);
int			parsing(int argc, char **argv);
void		print_and_free(const int i, const char *c, void *src, void **tab);
int			ft_string_is_num(char *src);
int			verif_time_eat(t_philo *args);
void		define_last_eat(t_philo *args);
t_philo		*ft_philonew(int i);
void		ft_philodelone(t_philo **list, void (*del)(void*));
void		ft_philoclear(t_philo **list, void (*del)(void*));
int			is_eat(t_philo *args);
int			is_sleep(t_philo *args);
void		print_message(t_philo *src, int msg);
long		get_time(void);
void		is_dead(t_philo *args);
int			verif_dead(t_philo *src);
long int	get_timestamp(long int start);
int			ft_usleep(size_t milliseconds);
void		ft_free_tab(void **tab);
void		init_src(t_philo *src, t_time *args);
t_time		*init_time(char **argv);
int			init_struct(t_philo **src, char **argv);
void		*philo(void *src);
void		reset_forks(t_philo *src);
int			check_philo_status(t_philo *args, int i);

#endif