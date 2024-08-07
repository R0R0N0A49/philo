/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:50:15 by trebours          #+#    #+#             */
/*   Updated: 2024/08/02 16:13:43 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_number(char **src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (ft_string_is_num(src[i]))
		{
			print_and_free(1, src[i], NULL, NULL);
			return (1);
		}
		if (ft_atoi(src[i]) == 0)
		{
			print_and_free(2, NULL, NULL, NULL);
			return (1);
		}
		i++;
	}
	return (0);
}

unsigned int	ft_ulatoi(const char *s1)
{
	int				i;
	unsigned int	rsl;

	i = 0;
	rsl = 0;
	if (!s1[i])
		return (rsl);
	while (s1[i] == 32 || (s1[i] >= '\t' && s1[i] <= '\r'))
		i++;
	if (s1[i] == '+')
		i++;
	while (s1[i] >= '0' && s1[i] <= '9')
	{
		rsl = rsl * 10 + (s1[i] - '0');
		i++;
	}
	return (rsl);
}

static int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

static int	ft_size(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i][0] == '-')
		{
			print_and_free(2, NULL, NULL, NULL);
			return (1);
		}
		if (ft_ulatoi(argv[i]) > 2147483647)
		{
			print_and_free(3, NULL, NULL, NULL);
			return (1);
		}
		if (ft_strlen(argv[i]) > 10)
		{
			print_and_free(3, NULL, NULL, NULL);
			return (1);
		}
		i++;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	if (argc != 6 && argc != 5)
	{
		print_and_free(0, NULL, NULL, NULL);
		return (1);
	}
	if (ft_size(argv))
		return (1);
	if (ft_number(argv))
		return (1);
	return (0);
}
