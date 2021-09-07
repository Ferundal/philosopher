#include "philo.h"

void	*destroy_philo_mutex(t_p_arg *p_arg_p, int counter)
{
	while (counter-- > 0)
	{
		pthread_mutex_destroy(&p_arg_p->p.d_t_acc);
		pthread_mutex_destroy(&p_arg_p->p.n_t_f_acc);
	}
	return (NULL);
}
