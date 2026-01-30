/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:05:05 by canoduran         #+#    #+#             */
/*   Updated: 2026/01/30 01:08:59 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_free_all(t_all *choose)
{
	if (choose->number_philo)
		free(choose->number_philo);
	if (choose->data.fork)
		free(choose->data.fork);
}