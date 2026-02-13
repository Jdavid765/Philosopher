/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: canoduran <canoduran@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 22:39:55 by david             #+#    #+#             */
/*   Updated: 2026/02/13 17:07:53 by canoduran        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct t_d
{
	int				time_eat;
	int				time_sleep;
	int				time_dead;
	int				nb_eat;
	int				routine_active;
	long int		time_start;
}	t_data;
typedef struct t_philo
{
	int				id_philo;
	int				nb_eat;
	long int		last_meal;
	pthread_mutex_t	meal_lock;
	long int		nb_philo;
	t_data			*data;
	pthread_t		threads;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;
typedef struct t_prog
{
	t_philo			*philo;
	t_data			data;
	int				nb_philo;
	int				*all_philo_eat;
	int				flag_nb_eat;
}	t_prog;

void		ft_free_all(t_prog *prog);

long int	ft_atoi(char *string);
int			parsing(t_prog *prog, char **av, int ac);

void		*routine(void *arg);

void		ft_supervisor(t_prog *prog);

void		print_message(char *string, t_philo *philo);

long int	get_time(void);
#endif 