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
	(void)p_a;
	*l_meal = ft_time(t_z);
}

int	is_dead(t_p_arg *p_a, t_comm_info *c_info, long long int time_to_d)
{
	long long int	curr_time;

	curr_time = ft_time(&c_info->t_zone);
	if (curr_time - time_to_d < p_a->p.l_meal)
	{
		return (0);
	}
	sem_wait(p_a->c_info.death_sem);
	overseer_output(curr_time, p_a);
	return (1);
}
