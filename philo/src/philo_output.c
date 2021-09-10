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
								t_p_arg *philo_arg)
{
	curr_time = (curr_time - philo_arg->c_info->start_t) / 1000;
	pthread_mutex_lock(&philo_arg->c_info->p_out_mut);
	pthread_mutex_lock(&philo_arg->c_info->death_mut);
	pthread_mutex_unlock(&philo_arg->c_info->death_mut);
	pthread_mutex_lock(&philo_arg->c_info->out_mut);
	printf("\033[%dm%lld %d %s\033[m\n", \
		philo_arg->p.color, curr_time, philo_arg->p.philo_id, str);
	pthread_mutex_unlock(&philo_arg->c_info->out_mut);
	pthread_mutex_unlock(&philo_arg->c_info->p_out_mut);
}

void	overseer_output(long long int curr_time, t_p_arg *philo_arg)
{
	curr_time = (curr_time - philo_arg->c_info->start_t) / 1000;
	pthread_mutex_lock(&philo_arg->c_info->out_mut);
	printf("\033[%dm%lld %d %s\033[m\n", \
		philo_arg->p.color, curr_time, philo_arg->p.philo_id, "died");
}
