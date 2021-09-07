#include "philo.h"

int	init_common_info(t_comm_info *c_info_p, \
					int argc, char **argv)
{
	c_info_p->t_zone.tz_minuteswest = 0;
	c_info_p->t_zone.tz_dsttime = 0;
	c_info_p->time_to_e = ft_atoi(argv[2]);
	c_info_p->time_to_d = ft_atoi(argv[1]) + c_info_p->time_to_e;
	c_info_p->time_to_e = c_info_p->time_to_e * 1000;
	c_info_p->time_to_s = ft_atoi(argv[3]) * 1000;
	if (argc < 5)
		c_info_p->num_to_feed = -1;
	else
		c_info_p->num_to_feed = ft_atoi(argv[4]);
	if (c_info_p->num_to_feed == 0)
		return (3);
	if (pthread_mutex_init(&c_info_p->death_mut, NULL))
		return (4);
	if (pthread_mutex_init(&c_info_p->out_mut, NULL))
		return (5);
	if (pthread_mutex_init(&c_info_p->p_out_mut, NULL))
		return (6);
	return (0);
}

pthread_mutex_t	*init_fork_array(int fork_amnt)
{
	pthread_mutex_t	*fork_arr;
	int				counter;

	fork_arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * fork_amnt);
	if (fork_arr == NULL)
		return (NULL);
	counter = 0;
	while (counter < fork_amnt)
	{
		if (pthread_mutex_init(fork_arr + counter, NULL) != 0)
		{
			while (counter > 0)
				pthread_mutex_destroy(fork_arr + --counter);
			free(fork_arr);
			return (NULL);
		}
		++counter;
	}
	return (fork_arr);
}

int		color_select(int num)
{
	num = num % 29;
	if (num < 7)
		num += 30;
	else if (num < 15)
		num += 33;
	else if (num < 22)
		num += 75;
	else
		num += 78;
	return (num);
}

void	swap_forks(pthread_mutex_t **f_fork, pthread_mutex_t **s_fork)
{
	pthread_mutex_t *temp_fork;

	temp_fork = *f_fork;
	*f_fork = *s_fork;
	*s_fork = temp_fork;
}

t_p_arg	*init_val(t_comm_info *c_info, int philo_amnt, \
					pthread_mutex_t *fork_arr)
{
	t_p_arg		*p_arg_p;
	int			counter;

	p_arg_p = (t_p_arg *)malloc(sizeof (t_p_arg) * philo_amnt);
	if (p_arg_p == NULL)
		return (NULL);
	counter = 0;
	while (counter < philo_amnt)
	{
		p_arg_p[counter].c_info = c_info;
		p_arg_p[counter].p.philo_id = counter + 1;
		p_arg_p[counter].p.color = color_select(counter);
		p_arg_p[counter].p.num_to_feed = c_info->num_to_feed;
		p_arg_p[counter].p.f_fork = fork_arr + counter;
		p_arg_p[counter].p.l_meal = -c_info->time_to_e / 1000;
		if (counter != 0)
			p_arg_p[counter].p.s_fork = fork_arr + counter - 1;
		else
			p_arg_p[counter].p.s_fork = fork_arr + philo_amnt - 1;
		++counter;
		if ((p_arg_p[counter].p.philo_id % 2) == 1)
			swap_forks(&p_arg_p[counter].p.f_fork, &p_arg_p[counter].p.s_fork);
	}
	return (p_arg_p);
}

