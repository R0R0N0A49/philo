/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trebours <trebours@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:48:02 by trebours          #+#    #+#             */
/*   Updated: 2024/07/04 11:09:38 by trebours         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	choice_msg(int i)
{
	if (i == 0)
		printf("to less or more argument\n");
	if (i == 1)
		printf("no't a number\n");
}

void    print_and_free(int i, void *src, void **tab)
{
	choice_msg(i);
	(void)src;
	(void)tab;
	// ft_free();
}
