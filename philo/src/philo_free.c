/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:43:59 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:44:00 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*destroy_philo_mutex(t_p_arg *p_arg_p, int counter)
{
	while (counter-- > 0)
	{
		pthread_mutex_destroy(&p_arg_p->p.d_t_acc);
		pthread_mutex_destroy(&p_arg_p->p.n_t_f_acc);
	}
	return (NULL);
}

int	clean(int status)
{
	return (status);
}
