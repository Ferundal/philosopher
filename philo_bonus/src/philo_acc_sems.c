/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acc_mutexes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:44:36 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:44:50 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_l_meal(long long int *l_meal, t_p_arg *p_a, \
												struct timezone *t_z)
{
	sem_wait(p_a->p.d_t_acc);
	*l_meal = ft_time(t_z);
	sem_post(p_a->p.d_t_acc);
}

int	is_dead(t_p_arg *p_a, t_comm_info *c_info, long long int time_to_d)
{
	long long int	curr_time;

	sem_wait(p_a->p.d_t_acc);
	curr_time = ft_time(&c_info->t_zone);
	if (curr_time - time_to_d < p_a->p.l_meal)
	{
		sem_post(p_a->p.d_t_acc);
		return (0);
	}
	overseer_output(curr_time, p_a);
	sem_wait(p_a->c_info.death_sem);
	sem_post(p_a->c_info.out_sem);
	return (1);
}
