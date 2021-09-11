/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:45:41 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:45:46 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char **argv)
{
	int		str_pos;

	if (argc < 4 || argc > 5)
	{
		put_err_msg("wrong argument amount\n");
		return (1);
	}
	str_pos = 0;
	while (argc > 0)
	{
		while ((*argv)[str_pos] != '\0')
		{
			if (ft_isdigit((*argv)[str_pos]) == 0)
			{
				put_err_msg("numeric argument required\n");
				return (1);
			}
			++str_pos;
		}
		--argc;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_comm_info		c_info;
	t_p_arg			*p_arg_p;
	int				philo_amnt;
	pthread_mutex_t	*fork_arr;
	int				status;

	if (check_args(--argc, ++argv) != 0)
		return (clean(1));
	philo_amnt = ft_atoi(*argv);
	if (philo_amnt < 1)
		return (clean(2));
	status = init_common_info(&c_info, argc, argv);
	if (status != 0)
		return (clean(status));
	fork_arr = init_fork_array(philo_amnt);
	if (fork_arr == NULL)
		return (clean(7));
	p_arg_p = init_philo(&c_info, philo_amnt, fork_arr);
	if (p_arg_p == NULL)
		return (clean(8));
	status = simulation(&c_info, p_arg_p, philo_amnt);
	return (clean(status));
}
