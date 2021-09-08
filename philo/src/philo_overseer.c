#include "philo.h"

void	p_overseer_unlim(t_comm_info *c_info, t_p_arg *p_arg_p, int philo_amnt)
{
	int				counter;
	long long int	curr_time;
	long long int	time_to_d;

	time_to_d = c_info->time_to_d;
	while(1)
	{
		curr_time = ft_time(&c_info->t_zone);
		counter = 0;
		while (counter < philo_amnt)
		{
			if (is_dead(p_arg_p, c_info, curr_time, time_to_d) != 0)
				return ;
			++counter;
		}
	}
}

int	philos_full(t_p_arg ***p_arg_ppp, int counter, int *philo_amnt)
{
	t_p_arg *temp_p_arg_p;
	t_p_arg **first_p_arg_p;
	t_p_arg **second_p_arg_p;

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
	long long int	curr_time;
	long long int	time_to_d;

	time_to_d = c_info->time_to_d;
	while(1)
	{
		curr_time = ft_time(&c_info->t_zone);
		counter = 0;
		while (counter < philo_amnt)
		{
			if (is_zero_num_to_feed(p_arg_pp[counter]) != 1)
			{
				if (is_dead(p_arg_pp[counter], c_info, curr_time, time_to_d) != 0)
					return;
			}
			else
				philos_full(&p_arg_pp, counter, &philo_amnt);
			++counter;
		}
		if (philo_amnt < 1)
			break ;
	}
}