/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:45:13 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:45:15 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	ft_time(struct timezone *t_zone)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, t_zone) != 0)
		return (-1);
	return (curr_time.tv_sec * 1000000 + curr_time.tv_usec);
}

void	philosopher_life_unlim(t_p_arg *p_a, \
							long long int time_to_e, long long int time_to_s)
{
	long long int	s_sleep;
	long long int	*l_meal;
	struct timezone	*t_z;

	t_z = &p_a->c_info->t_zone;
	l_meal = &p_a->p.l_meal;
	wait_start(p_a);
	while (1)
	{
		pthread_mutex_lock(p_a->p.f_fork);
		philo_output("has taken a fork", ft_time(t_z), p_a);
		pthread_mutex_lock(p_a->p.s_fork);
		philo_output("has taken a fork", ft_time(t_z), p_a);
		set_l_meal(l_meal, p_a, t_z);
		philo_output("is eating", *l_meal, p_a);
		my_usleep(time_to_e);
		pthread_mutex_unlock(p_a->p.f_fork);
		pthread_mutex_unlock(p_a->p.s_fork);
		s_sleep = ft_time(t_z);
		philo_output("is sleeping", s_sleep, p_a);
		my_usleep(time_to_s);
		philo_output("is thinking", ft_time(t_z), p_a);
	}
}

void	philosopher_life_lim(t_p_arg *p_a, \
			long long int time_to_e, long long int time_to_s, int *num_to_feed)
{
	long long int	s_sleep;
	long long int	*l_meal;
	struct timezone	*t_z;

	t_z = &p_a->c_info->t_zone;
	l_meal = &p_a->p.l_meal;
	wait_start(p_a);
	while (1)
	{
		pthread_mutex_lock(p_a->p.f_fork);
		philo_output("has taken a fork", ft_time(t_z), p_a);
		pthread_mutex_lock(p_a->p.s_fork);
		philo_output("has taken a fork", ft_time(t_z), p_a);
		set_l_meal(l_meal, p_a, t_z);
		philo_output("is eating", *l_meal, p_a);
		my_usleep(time_to_e);
		pthread_mutex_unlock(p_a->p.f_fork);
		pthread_mutex_unlock(p_a->p.s_fork);
		if (--*num_to_feed == 0)
			break ;
		s_sleep = ft_time(t_z);
		philo_output("is sleeping", s_sleep, p_a);
		my_usleep(time_to_s);
		philo_output("is thinking", ft_time(t_z), p_a);
	}
}

void	*philo_life_lim_start(void *p_a)
{
	philosopher_life_lim((t_p_arg *)p_a, \
								((t_p_arg *)p_a)->c_info->time_to_e, \
								((t_p_arg *)p_a)->c_info->time_to_s, \
								(&((t_p_arg *)p_a)->p.num_to_feed));
	return (0);
}

void	*philo_life_unlim_start(void *p_a)
{
	philosopher_life_unlim((t_p_arg *)p_a, \
								((t_p_arg *)p_a)->c_info->time_to_e, \
								((t_p_arg *)p_a)->c_info->time_to_s);
	return (0);
}
