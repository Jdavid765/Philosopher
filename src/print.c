/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 21:02:52 by canoduran         #+#    #+#             */
/*   Updated: 2026/02/13 01:07:06 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	print_message(char *string, t_philo *philo)
{
	long int	timestamp;

	timestamp = get_time() - philo->data->time_start;
	printf("%ld, %s = %d\n", timestamp, string, philo->id_philo);
}
