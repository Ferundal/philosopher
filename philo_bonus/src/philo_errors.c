/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:44:15 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:44:17 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_err_msg(char *str)
{
	int		str_len;

	str_len = 0;
	while (str[str_len] != '\0')
		++str_len;
	write(2, str, str_len);
}
