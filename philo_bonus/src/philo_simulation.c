/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:39:49 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:39:51 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*global_overseer(void *p_a_v)
{
	t_p_arg	*p_a;
	int		counter;

	p_a = (t_p_arg *)p_a_v;
	counter = 0;
	while (counter++ < p_a->c_info.philo_amnt)
	{
		sem_wait(p_a->c_info.job_done_sem);
	}
	sem_post(p_a->c_info.quit_sem);
	return (NULL);
}

void	simulation_lim(t_p_arg *p_a)
{
	int				counter;
	pid_t			pid;

	counter = 0;
	while (counter < p_a->c_info.philo_amnt)
	{
		pid = fork();
		if (pid == 0)
		{
			init_philo(p_a, counter);
			p_overseer_lim(&p_a->c_info, p_a);
			sem_post(p_a->c_info.job_done_sem);
			exit(0);
		}
		++counter;
	}
	counter = 0;
	pthread_create(&p_a->c_info.g_overseer, NULL, global_overseer, p_a);
	while (counter++ < p_a->c_info.philo_amnt)
		sem_post(p_a->c_info.start_sem);
	sem_wait(p_a->c_info.quit_sem);
	kill(0, SIGQUIT);
}

void	simulation_unlim(t_p_arg *p_a)
{
	int				counter;
	pid_t			pid;

	counter = 0;
	while (counter < p_a->c_info.philo_amnt)
	{
		pid = fork();
		if (pid == 0)
		{
			init_philo(p_a, counter);
			p_overseer_unlim(&p_a->c_info, p_a);
			exit(0);
		}
		++counter;
	}
	counter = 0;
	while (counter++ < p_a->c_info.philo_amnt)
		sem_post(p_a->c_info.start_sem);
	sem_wait(p_a->c_info.quit_sem);
	kill(0, SIGQUIT);
}

void	simulation(t_p_arg *p_a)
{
	if (p_a->c_info.num_to_feed < 0)
		simulation_unlim(p_a);
	else
		simulation_lim(p_a);
}
