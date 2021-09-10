/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_usleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:34:27 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:34:29 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(long long int	time_to_sleep)
{
	struct timeval	curr_time;
	ssize_t			start_time;

	gettimeofday(&curr_time, NULL);
	start_time = curr_time.tv_sec * 1000000 + curr_time.tv_usec;
	while (time_to_sleep > ((curr_time.tv_sec * 1000000 \
							+ curr_time.tv_usec - start_time)))
	{
		gettimeofday(&curr_time, NULL);
		usleep(100);
	}
}
