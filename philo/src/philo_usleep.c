#include "philo.h"

void	my_usleep(long long int	time_to_sleep)
{
	struct timeval	curr_time;
	ssize_t			start_time;

	gettimeofday(&curr_time, NULL);
	start_time = curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000;
	while (time_to_sleep > ((curr_time.tv_sec * 1000 + curr_time.tv_usec / 1000) - start_time))
	{
		gettimeofday(&curr_time, NULL);
		usleep(100);
	}
}