/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:41:54 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:41:56 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_output(char *str, long long int curr_time, \
								t_p_arg *p_a)
{
	curr_time = (curr_time - p_a->c_info.start_t) / 1000;
	sem_wait(p_a->c_info.p_out_sem);
	sem_wait(p_a->c_info.death_sem);
	sem_post(p_a->c_info.death_sem);
	sem_wait(p_a->c_info.out_sem);
	printf("\033[%dm%lld %d %s\033[m\n", \
		p_a->p.color, curr_time, p_a->p.philo_id, str);
	sem_post(p_a->c_info.out_sem);
	sem_post(p_a->c_info.p_out_sem);
}

void	overseer_output(long long int curr_time, t_p_arg *p_a)
{
	curr_time = (curr_time - p_a->c_info.start_t) / 1000;
	sem_wait(p_a->c_info.out_sem);
	printf("\033[%dm%lld %d %s\033[m\n", \
		p_a->p.color, curr_time, p_a->p.philo_id, "died");
	sem_post(p_a->c_info.quit_sem);
}
