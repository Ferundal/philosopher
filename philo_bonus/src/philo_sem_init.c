/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sem_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 18:26:53 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/12 18:26:55 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

sem_t	*init_sem_philo(char const *str, int val)
{
	sem_t	*result;

	sem_unlink(str);
	result = sem_open(str, O_CREAT | O_EXCL, S_IRWXU, val);
	sem_unlink(str);
	return (result);
}
