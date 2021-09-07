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
			if (curr_time - p_arg_p[counter].p.l_meal > time_to_d)
			{
				pthread_mutex_lock(&c_info->death_mut);
				overseer_output(curr_time, p_arg_p + counter);
				return ;
			}
			++counter;
		}
	}
}

int	philos_full(t_p_arg ***p_arg_pp, int counter, int *philo_amnt)
{
	t_p_arg *temp_p_arg_p;
	t_p_arg **first_p_arg_p;
	t_p_arg **second_p_arg_p;

	if (*philo_amnt > 1)
	{
		first_p_arg_p = *p_arg_pp;
		second_p_arg_p = *p_arg_pp + counter;
		temp_p_arg_p = *first_p_arg_p;
		*first_p_arg_p = *second_p_arg_p;
		*second_p_arg_p = temp_p_arg_p;
		++*p_arg_pp;
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
			if (p_arg_pp[counter]->p.num_to_feed != 0)
			{
				if (curr_time - p_arg_pp[counter]->p.l_meal > time_to_d)
				{
					pthread_mutex_lock(&c_info->death_mut);
					overseer_output(curr_time, p_arg_pp[counter]);
					return;
				}
				++counter;
			}
			else
				philos_full(&p_arg_pp, counter, &philo_amnt);
		if (philo_amnt < 1)
			break ;
	}
}