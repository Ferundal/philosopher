#include "philo.h"

long long int	set_l_meal(long long int *l_meal, t_p_arg *p_a, \
												struct timezone *t_z)
{
	long long int	ret_val;

	pthread_mutex_lock(&p_a->p.d_t_acc);
	ret_val = ft_time(t_z);
	*l_meal = ret_val;
	pthread_mutex_unlock(&p_a->p.d_t_acc);
	return (ret_val);
}

int	is_dead(t_p_arg *p_arg_p, t_comm_info *c_info, \
							long long int curr_time, long long int time_to_d)
{
	pthread_mutex_lock(&p_arg_p->p.d_t_acc);
	if (curr_time - p_arg_p->p.l_meal < time_to_d)
	{
		pthread_mutex_unlock(&p_arg_p->p.d_t_acc);
		return (0);
	}
	pthread_mutex_lock(&c_info->death_mut);
	overseer_output(curr_time, p_arg_p);
	return (1);
}

int	is_zero_and_decrease_num_to_feed(t_p_arg *p_a, int *num_to_feed)
{
	pthread_mutex_lock(&p_a->p.n_t_f_acc);
	--*num_to_feed;
	if (*num_to_feed == 0)
	{
		pthread_mutex_unlock(&p_a->p.n_t_f_acc);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&p_a->p.n_t_f_acc);
		return (0);
	}
}

int	is_zero_num_to_feed(t_p_arg *p_a)
{
	pthread_mutex_lock(&p_a->p.n_t_f_acc);
	if (p_a->p.num_to_feed == 0)
	{
		pthread_mutex_unlock(&p_a->p.n_t_f_acc);
		return (1);
	}
	pthread_mutex_unlock(&p_a->p.n_t_f_acc);
	return (0);
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