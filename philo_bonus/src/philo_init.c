/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:42:38 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:42:58 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_common_info_arg(t_comm_info *c_info_p, \
								int argc, char **argv)
{
	c_info_p->t_zone.tz_minuteswest = 0;
	c_info_p->t_zone.tz_dsttime = 0;
	c_info_p->time_to_d = ft_atoi(argv[1]) * 1000;
	c_info_p->time_to_e = ft_atoi(argv[2]) * 1000;
	c_info_p->time_to_s = ft_atoi(argv[3]) * 1000;
	if (argc < 5)
		c_info_p->num_to_feed = -1;
	else
		c_info_p->num_to_feed = ft_atoi(argv[4]);
}

int	init_common_sems(t_comm_info *c_info_p)
{
	if (c_info_p->death_sem == SEM_FAILED)
		return (4);
	c_info_p->out_sem = init_sem_philo("philo_out_sem", 1);
	if (c_info_p->death_sem == SEM_FAILED)
		return (5);
	c_info_p->p_out_sem = init_sem_philo("philo_p_out_sem", 1);
	if (c_info_p->death_sem == SEM_FAILED)
		return (6);
	c_info_p->forks = init_sem_philo("philo_forks", c_info_p->philo_amnt);
	if (c_info_p->forks == SEM_FAILED)
		return (7);
	c_info_p->quit_sem = init_sem_philo("philo_quit_sem", 0);;
	if (c_info_p->quit_sem == SEM_FAILED)
		return (8);
	c_info_p->start_sem= init_sem_philo("philo_start_sem", 0);;
	if (c_info_p->start_sem == SEM_FAILED)
		return (9);
	c_info_p->job_done_sem = init_sem_philo("philo_active_sem", 0);;
	if (c_info_p->job_done_sem == SEM_FAILED)
		return (10);
	return (0);
}

int	init_common_info(t_comm_info *c_info_p, int argc, char **argv)
{
	int		status;

	init_common_info_arg(c_info_p, argc, argv);
	if (c_info_p->num_to_feed == 0)
		return (3);
	status = init_common_sems(c_info_p);
	if (status != 0)
		return (status);
	return (0);
}

int	color_select(int num)
{
	num = num % 27;
	if (num < 1)
		num += 7;
	if (num < 7)
		num += 31;
	else if (num < 15)
		num += 33;
	else if (num < 22)
		num += 75;
	else
		num += 78;
	return (num);
}

void	init_philo(t_p_arg *p_arg_p, int counter)
{
	char	*counter_to_str;

	counter_to_str = ft_itoa(counter);
	p_arg_p->p.philo_id = counter + 1;
	p_arg_p->p.color = color_select(counter);
	p_arg_p->p.num_to_feed = p_arg_p->c_info.num_to_feed;
	p_arg_p->p.d_t_acc = init_sem_philo(counter_to_str, 0);
	if (p_arg_p->p.d_t_acc == SEM_FAILED)
		exit (0);
	sem_unlink(counter_to_str);
	p_arg_p->p.n_t_f_acc = init_sem_philo(counter_to_str, 0);
	if (p_arg_p->p.n_t_f_acc == SEM_FAILED)
		exit (0);
	sem_unlink(counter_to_str);
}
