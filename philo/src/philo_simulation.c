#include "philo.h"

t_p_arg			**create_lim_observer_arg(t_comm_info *c_info, \
								t_p_arg *p_arg_p, int philo_amnt)
{
	t_p_arg		**p_arg_pp;

	if (c_info->num_to_feed < 0)
		return (NULL);
	p_arg_pp = (t_p_arg **) malloc(sizeof(t_p_arg *) * philo_amnt);
	if (p_arg_pp == NULL)
		return (NULL);
	while (philo_amnt-- > 0)
	{
		p_arg_pp[philo_amnt] = p_arg_p + philo_amnt;
	}
	return (p_arg_pp);
}

int	simulation(t_comm_info *c_info, t_p_arg *p_arg_p, int philo_amnt)
{
	pthread_t		*tread_p;
	int				i;
	long long int	start_t;
	t_p_arg			**p_arg_pp;

	tread_p = (pthread_t *) malloc(sizeof(pthread_t) * philo_amnt);
	if (tread_p == NULL)
		return (8);
	p_arg_pp = create_lim_observer_arg(c_info, p_arg_p, philo_amnt);
	if (c_info->num_to_feed >= 0 && p_arg_pp == NULL)
		return (9);
	i = 0;
	start_t = ft_time(&c_info->t_zone);
	c_info->start_t = start_t;
	while (i < philo_amnt)
	{
		(p_arg_p + i)->p.l_meal += start_t;
		pthread_create(tread_p + i, NULL, philosopher_life, p_arg_p + i);
		++i;
	}
	if (c_info->num_to_feed < 0)
		p_overseer_unlim(c_info, p_arg_p, philo_amnt);
	else
		p_overseer_lim(c_info, p_arg_pp, philo_amnt);
	return (0);
}