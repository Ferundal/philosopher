#include "philo.h"

sem_t	*init_sem_philo(char const *str, int val)
{
	sem_t	*result;

	result = sem_open(str, O_CREAT | O_EXCL, S_IRWXU, val);
	sem_unlink(str);
	return (result);
}