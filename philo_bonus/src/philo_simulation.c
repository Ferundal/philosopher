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



void	philo_life_start(t_p_arg *p_a)
{

}

void	*global_overseer(void *p_a_v)
{
	t_p_arg	*p_a;
	int		counter;

	p_a = (t_p_arg *)p_a_v;
	counter = 0;
	while (counter < p_a)
}

void	simulation_lim(t_p_arg *p_a)
{
	int				counter;
	pid_t			pid;

	counter = 0;
	while (counter < p_a->c_info.philo_amnt)
	{
		init_philo(p_a, counter);
		pid = fork();
		if (pid == 0)
		{
			philo_life_start(p_a);
			exit(0);
		}
		++counter;
	}
	counter = 0;
	while (counter++ < p_a->c_info.philo_amnt)
		sem_post(p_a->c_info.start_sem);
	sem_wait(p_a->c_info.quit_sem);
	kill(0, SIGQUIT);
	exit(0);
}

void	simulation_unlim(t_p_arg *p_a)
{
	int				counter;
	pid_t			pid;

	counter = 0;
	while (counter < p_a->c_info.philo_amnt)
	{
		init_philo(p_a, counter);
		pid = fork();
		if (pid == 0)
		{
			philo_life_start(p_a);
			exit(0);
		}
		++counter;
	}
	counter = 0;
	pthread_create(p_a->c_info.g_overseer, NULL, global_overseer, p_a);
	while (counter++ < p_a->c_info.philo_amnt)
		sem_post(p_a->c_info.start_sem);
	sem_wait(p_a->c_info.quit_sem);
	kill(0, SIGQUIT);
	exit(0);
}

void	simulation(t_p_arg *p_a)
{
	int				counter;
	pid_t			pid;

	counter = 0;
	while (counter < p_a->c_info.philo_amnt)
	{
		init_philo(p_a, counter);
		pid = fork();
		if (pid == 0)
		{
			philo_life_start(p_a);
			exit(0);
		}
		++counter;
	}
	counter = 0;
	while (counter++ < p_a->c_info.philo_amnt)
		sem_post(p_a->c_info.start_sem);
	sem_wait(p_a->c_info.quit_sem);
	kill(0, SIGQUIT);
	exit(0);
}

