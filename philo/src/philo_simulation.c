#include "philo.h"

int	create_lim_observer_arg(t_p_arg ***p_arg_ppp, \
							t_p_arg *p_arg_p, int philo_amnt)
{
	t_p_arg **p_arg_pp;

	p_arg_pp = (t_p_arg **) malloc(sizeof(t_p_arg *) * philo_amnt);
	if (p_arg_pp == NULL)
		return (1);
	while (philo_amnt-- > 0)
	{
		p_arg_pp[philo_amnt] = p_arg_p + philo_amnt;
	}
	*p_arg_ppp = p_arg_pp;
	return (0);
}

int	simulatiion_unlim(t_comm_info *c_info, t_p_arg *p_arg_p, int philo_amnt, pthread_t *tread_p)
{
	int				i;
	long long int	start_t;

	i = 0;
	start_t = ft_time(&c_info->t_zone);
	c_info->start_t = start_t;
	while (i < philo_amnt)
	{
		(p_arg_p + i)->p.l_meal = start_t;
		pthread_create(tread_p + i, NULL, philo_life_unlim_start, p_arg_p + i);
		i += 2;
	}
	usleep(c_info->time_dealay - (ft_time(&c_info->t_zone) - start_t));
	i = 1;
	while (i < philo_amnt)
	{
		(p_arg_p + i)->p.l_meal = start_t;
		pthread_create(tread_p + i, NULL, philo_life_unlim_start, p_arg_p + i);
		i += 2;
	}
	p_overseer_unlim(c_info, p_arg_p, philo_amnt);
	return (0);
}

int	simulatiion_lim(t_comm_info *c_info, t_p_arg *p_arg_p, int philo_amnt, pthread_t *tread_p)
{
	int				i;
	long long int	start_t;
	t_p_arg			**p_arg_pp;

	if (create_lim_observer_arg(&p_arg_pp, p_arg_p, philo_amnt) != 0)
		return (9);
	i = 0;
	start_t = ft_time(&c_info->t_zone);
	c_info->start_t = start_t;
	while (i < philo_amnt)
	{
		(p_arg_p + i)->p.l_meal = start_t;
		pthread_create(tread_p + i, NULL, philo_life_lim_start, p_arg_p + i);
		i += 2;
	}
	usleep(c_info->time_dealay - (ft_time(&c_info->t_zone) - start_t));
	i = 1;
	while (i < philo_amnt)
	{
		(p_arg_p + i)->p.l_meal = start_t;
		pthread_create(tread_p + i, NULL, philo_life_lim_start, p_arg_p + i);
		i += 2;
	}
	p_overseer_lim(c_info, p_arg_pp, philo_amnt);
	free (p_arg_pp);
	return (0);
}

int	simulation(t_comm_info *c_info, t_p_arg *p_arg_p, int philo_amnt)
{
	pthread_t		*tread_p;

	tread_p = (pthread_t *) malloc(sizeof(pthread_t) * philo_amnt);
	if (tread_p == NULL)
		return (8);
	if (c_info->num_to_feed < 0)
		simulatiion_unlim(c_info, p_arg_p, philo_amnt, tread_p);
	else
		simulatiion_lim(c_info, p_arg_p, philo_amnt, tread_p);
	return (0);
}