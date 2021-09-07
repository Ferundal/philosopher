#include "philo.h"

long long int	ft_time(struct timezone *t_zone)
{
	struct timeval	curr_time;

	if (gettimeofday(&curr_time, t_zone) != 0)
		return (-1);
	return (curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000);
}

void	philo_sleep(long long int time)
{
	usleep(time);
}

void	philosopher_life_unlim(t_p_arg *p_a, \
								int time_to_e, int time_to_s)
{
	long long int	s_sleep;
	long long int	*l_meal;
	struct timezone	*t_z;

	t_z = &p_a->c_info->t_zone;
	l_meal = &p_a->p.l_meal;
	while (1)
	{
		philo_output("is thinking", ft_time(t_z), p_a);
		pthread_mutex_lock(p_a->p.f_fork);
		philo_output("has taken a fork", ft_time(t_z), p_a);
		pthread_mutex_lock(p_a->p.s_fork);
		philo_output("has taken a fork", ft_time(t_z), p_a);
		*l_meal = ft_time(t_z);
		philo_output("is eating", *l_meal, p_a);
		usleep(time_to_e - (*l_meal - ft_time(t_z)));
		pthread_mutex_unlock(p_a->p.f_fork);
		pthread_mutex_unlock(p_a->p.s_fork);
		s_sleep = ft_time(t_z);
		philo_output("is sleeping", s_sleep, p_a);
		usleep(time_to_s - (s_sleep - ft_time(t_z)));
	}
}

void	philosopher_life_lim(t_p_arg *p_a, \
							int time_to_e, int time_to_s, int *num_to_feed)
{
	long long int	s_sleep;
	long long int	*l_meal;
	struct timezone	*t_z;

	t_z = &(p_a->c_info->t_zone);
	l_meal = &p_a->p.l_meal;
	while (1)
	{
		philo_output("is thinking", ft_time(t_z), p_a);
		pthread_mutex_lock(p_a->p.f_fork);
		philo_output("has taken a fork", ft_time(t_z), p_a);
		pthread_mutex_lock(p_a->p.s_fork);
		philo_output("has taken a fork", ft_time(t_z), p_a);
		*l_meal = ft_time(t_z);
		philo_output("is eating", *l_meal, p_a);
		usleep(time_to_e - (*l_meal - ft_time(t_z)));
		pthread_mutex_unlock(p_a->p.f_fork);
		pthread_mutex_unlock(p_a->p.s_fork);
		if (--*num_to_feed < 1)
			break ;
		s_sleep = ft_time(t_z);
		philo_output("is sleeping", s_sleep, p_a);
		usleep(time_to_s - (s_sleep - ft_time(t_z)));
	}
}

void	*philosopher_life(void *p_a)
{
	if (((t_p_arg *)p_a)->c_info->num_to_feed < 0)
		philosopher_life_unlim((t_p_arg *)p_a, \
								((t_p_arg *)p_a)->c_info->time_to_e, \
								((t_p_arg *)p_a)->c_info->time_to_s);
	else
		philosopher_life_lim((t_p_arg *)p_a, \
								((t_p_arg *)p_a)->c_info->time_to_e, \
								((t_p_arg *)p_a)->c_info->time_to_s, \
								(&((t_p_arg *)p_a)->p.num_to_feed));
	return (0);
}