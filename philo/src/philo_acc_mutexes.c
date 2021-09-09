#include "philo.h"

void	set_l_meal(long long int *l_meal, t_p_arg *p_a, \
												struct timezone *t_z)
{
	pthread_mutex_lock(&p_a->p.d_t_acc);
	*l_meal = ft_time(t_z);
	pthread_mutex_unlock(&p_a->p.d_t_acc);
}

int	is_dead(t_p_arg *p_arg_p, t_comm_info *c_info, long long int time_to_d)
{
	long long int curr_time;

	pthread_mutex_lock(&p_arg_p->p.d_t_acc);
	curr_time = ft_time(&c_info->t_zone);
	if (curr_time - time_to_d < p_arg_p->p.l_meal)
	{
		pthread_mutex_unlock(&p_arg_p->p.d_t_acc);
		return (0);
	}
	pthread_mutex_lock(&c_info->death_mut);
	overseer_output(curr_time, p_arg_p);
	return (1);
}

int	init_philo_acc_mutexes(t_p_arg *p_a)
{
	if (pthread_mutex_init(&p_a->p.d_t_acc, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&p_a->p.n_t_f_acc, NULL) != 0)
	{
		pthread_mutex_destroy(&p_a->p.d_t_acc);
		return (1);
	}
	return (0);
}