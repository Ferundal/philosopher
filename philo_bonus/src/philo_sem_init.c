#include "philo.h"

sem_t	*init_sem_philo(char const *str, int val)
{
	sem_t	*result;
	int		counter;
	char	*str_counter;
	char	*new_str;
	int		new_size;

	result = sem_open(str, O_CREAT | O_EXCL, S_IRWXU, 1);
	if (result != SEM_FAILED)
		return (result);
	counter = 0;
	while (counter <= INT_MAX)
	{
		new_size = ft_strlen(str) + ft_num_amount(counter) + 1;
		new_str = (char *) malloc(sizeof(char) * new_size);
		ft_strlcpy(new_str, str, new_size);
		str_counter = ft_itoa(counter);
		ft_strlcat(new_str, str_counter, new_size);
		result = sem_open(new_str, O_CREAT | O_EXCL, S_IRWXU, 1);
		free(new_str);
		free(str_counter);
		if (result != SEM_FAILED)
			break ;
		++counter;
	}
	return (result);
}