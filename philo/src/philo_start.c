#include "philo.h"

void	wait_start(t_p_arg *p_a)
{
	int				*start;
	long long int	dealay;

	start = &p_a->c_info->start;
	if (p_a->c_info->time_to_e * 2 + p_a->c_info->time_to_s - \
		p_a->c_info->time_to_d > 0 && p_a->c_info->time_to_e * 2 \
		< p_a->c_info->time_to_d)
	{
		dealay = p_a->c_info->time_to_e * 3 - p_a->c_info->time_to_d;
		if ((p_a->c_info->philo_amnt % 2 == 1) && \
		(p_a->p.philo_id == p_a->c_info->philo_amnt - 1))
		dealay = p_a->c_info->time_to_e / 2 * 3;
		else if ((p_a->c_info->philo_amnt % 2 == 1) && \
		(p_a->p.philo_id == p_a->c_info->philo_amnt))
		dealay = (p_a->c_info->time_to_d - p_a->c_info->time_to_e * 2) / 2;
		else if (p_a->p.philo_id % 2 == 0)
			dealay = dealay * 3072 / (p_a->c_info->philo_amnt - 1) * (p_a->c_info->philo_amnt + 1)/ 2028;
		else
			dealay = dealay * 3072 / (p_a->c_info->philo_amnt - 3)  * (p_a->p.philo_id - 1) / 2028;
	}
	else
	{
		if (p_a->c_info->time_to_e > p_a->c_info->time_to_d)
			dealay = p_a->c_info->time_to_d / 2;
		else if (p_a->c_info->time_to_e * 3 - p_a->c_info->time_to_d < 0)
			dealay = p_a->c_info->time_to_e / 2;
		if (p_a->p.philo_id % 2 == 1)
			dealay = 0;
	}
	while (*start == 0);
	my_usleep(dealay);
}