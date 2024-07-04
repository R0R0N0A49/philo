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

int	parsing(int argc, char **argv)
{
	if (argc != 6 && argc != 5)
	{
		print_and_free(0, NULL, NULL, NULL);
		return (1);
	}
	if (ft_number(argv))
		return (1);
	return (0);
}
