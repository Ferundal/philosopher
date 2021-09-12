/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:35:14 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:35:16 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	special_start(long long int *dealay, t_p_arg *p_a)
{
	*dealay = p_a->c_info->time_to_e * 3 - p_a->c_info->time_to_d;
	if (*dealay <= 0)
		*dealay = p_a->c_info->time_to_e - 10000;
	if ((p_a->c_info->philo_amnt % 2 == 1) && \
	(p_a->p.philo_id == p_a->c_info->philo_amnt - 1))
		*dealay = p_a->c_info->time_to_e / 2 * 3;
	else if ((p_a->c_info->philo_amnt % 2 == 1) && \
	(p_a->p.philo_id == p_a->c_info->philo_amnt))
		*dealay = (p_a->c_info->time_to_d - p_a->c_info->time_to_e * 2) / 2;
	else if (p_a->p.philo_id % 2 == 0)
		*dealay = *dealay * 3 / (p_a->c_info->philo_amnt - 1) \
									* (p_a->c_info->philo_amnt + 1) / 2;
	else
		*dealay = *dealay * 3 / (p_a->c_info->philo_amnt - 3) \
											* (p_a->p.philo_id - 1) / 2;
}

void	wait_start(t_p_arg *p_a)
{
	int				*start;
	long long int	dealay;

	start = &p_a->c_info->start;
	if (p_a->c_info->time_to_e * 2 + p_a->c_info->time_to_s \
		> p_a->c_info->time_to_d - 11000 && p_a->c_info->philo_amnt % 2 == 1)
		special_start(&dealay, p_a);
	else
	{
		if (p_a->c_info->time_to_e > p_a->c_info->time_to_d)
			dealay = p_a->c_info->time_to_d / 2;
		else
			dealay = p_a->c_info->time_to_e / 2;
		if (p_a->p.philo_id % 2 == 1)
			dealay = 0;
	}
	while (*start == 0)
		(void)start;
	my_usleep(dealay);
}
