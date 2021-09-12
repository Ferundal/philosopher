/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_overseer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:40:06 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:40:08 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_overseer_unlim(t_comm_info *c_info, t_p_arg *p_a_p)
{
	long long int	time_to_d;
	pthread_t		tread;

	time_to_d = c_info->time_to_d;
	c_info->start = 0;
	pthread_create(&tread, NULL, philo_life_lim_start, p_a_p);
	c_info->start = 1;
	while (1)
	{
		if (is_dead(p_a_p, c_info, time_to_d) != 0)
			return ;
	}
}

void	p_overseer_lim(t_comm_info *c_info, t_p_arg *p_a_p)
{
	long long int	time_to_d;
	pthread_t		tread;

	time_to_d = c_info->time_to_d;
	sem_wait(c_info->start_sem);
	c_info->start = 0;
	pthread_create(&tread, NULL, philo_life_lim_start, p_a_p);
	c_info->start = 1;
	while (p_a_p->p.num_to_feed != 0)
	{
		if (is_dead(p_a_p, c_info, time_to_d) != 0)
			return ;
	}
}
