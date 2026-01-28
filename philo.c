/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:35:01 by david             #+#    #+#             */
/*   Updated: 2026/01/28 17:49:06 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int mail = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void	*routine()
{
	pthread_mutex_lock(&mutex);
	for(int i = 0; i < 1000000; i++)
	{
		mail++;
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int main(void)
{
	pthread_t p1, p2;

	if (pthread_create(&p1, NULL, routine, NULL) != 0)
		return (1);
	if (pthread_create(&p2, NULL, routine, NULL) != 0)
		return (1);

	pthread_join(p1, NULL);
    pthread_join(p2, NULL);
	printf("%d\n", mail);
	return (0);
}