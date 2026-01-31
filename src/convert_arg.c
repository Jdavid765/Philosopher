/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:00:23 by canoduran         #+#    #+#             */
/*   Updated: 2026/01/31 13:06:54 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int		ft_atoi(char *string)
{
	int	min;
	int	res;
	int	i;

	min = 1;
	res = 0;
	i = 0;
	while (string[i] == 32 || (string[i] >= 9 && string[i] <= 13))
		i++;
	
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			min *= -1;
		i++;
	}
	while (string[i] >= 48 && string[i] <= 57)
	{
		res = res * 10 + (string[i] - '0');
		i++;
	}
	return (res * min);
}
