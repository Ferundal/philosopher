#include "philo.h"

void	wait_start(t_p_arg *p_a)
{
	int				*start;
	long long int	dealay;

	start = &p_a->c_info->start;
	if (p_a->p.philo_id % 2 == 0)
		dealay = 10;
	else
		dealay = 0;
	while (*start == 0);
	my_usleep(dealay);
}