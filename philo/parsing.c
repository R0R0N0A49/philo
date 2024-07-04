/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:50:15 by trebours          #+#    #+#             */
/*   Updated: 2024/07/04 11:45:06 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	ft_number(char **src)
{
	int	i;
	int	j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (src[i][j])
		{
			if (src[i][j] < '0' || src[i][j] > '9')
			{
				print_and_free(1, src[i][j], NULL, NULL);
				return (1);
			}
				j++;
		}
		if (ft_atoi(src[i]) == 0)
		{
			print_and_free(2, 0, NULL, NULL);
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
		// ft_printf_error_and_free
			// ("to many or less argument, you need 4 or 5 argument", NULL, NULL);
		print_and_free(0, 0, NULL, NULL);
		return (1);
	}
	if (ft_number(argv))
	{
		// ft_printf_error_and_free("bad imput", NULL, NULL);
		return (1);
	}
	return (0);
}
