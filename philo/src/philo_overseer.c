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

void	p_overseer_unlim(t_comm_info *c_info, t_p_arg *p_arg_p, int philo_amnt)
{
	int				counter;
	long long int	time_to_d;

	time_to_d = c_info->time_to_d;
	while (1)
	{
		counter = 0;
		while (counter < philo_amnt)
		{
			if (is_dead(p_arg_p, c_info, time_to_d) != 0)
				return ;
			++counter;
		}
	}
}

int	philos_full(t_p_arg ***p_arg_ppp, int counter, int *philo_amnt)
{
	t_p_arg	*temp_p_arg_p;
	t_p_arg	**first_p_arg_p;
	t_p_arg	**second_p_arg_p;

	if (*philo_amnt > 1)
	{
		if (counter > 0)
		{
			first_p_arg_p = *p_arg_ppp;
			second_p_arg_p = *p_arg_ppp + counter;
			temp_p_arg_p = *first_p_arg_p;
			*first_p_arg_p = *second_p_arg_p;
			*second_p_arg_p = temp_p_arg_p;
		}
		++*p_arg_ppp;
	}
	--*philo_amnt;
	return (0);
}

void	p_overseer_lim(t_comm_info *c_info, t_p_arg **p_arg_pp, int philo_amnt)
{
	int				counter;
	long long int	time_to_d;

	time_to_d = c_info->time_to_d;
	while (1)
	{
		counter = 0;
		while (counter < philo_amnt)
		{
			if (p_arg_pp[counter]->p.num_to_feed != 0)
			{
				if (is_dead(p_arg_pp[counter], c_info, time_to_d) != 0)
					return ;
			}
			else
				philos_full(&p_arg_pp, counter, &philo_amnt);
			++counter;
		}
		if (philo_amnt < 1)
			break ;
	}
}
