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
	if (i == 3)
		printf("values must be less than MAX_INT\n");
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
