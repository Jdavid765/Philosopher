/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:01:54 by canoduran         #+#    #+#             */
/*   Updated: 2026/01/28 21:07:36 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	init(t_all *choose)
{
	choose->data.time_eat = 0;
	choose->data.time_dead = 0;
	choose->data.time_sleep = 0;
	choose->data.time_thinks = 0;
	choose->data.fork = NULL;
}