#include "philo.h"

void	put_err_msg(char *str)
{
	int		str_len;

	str_len = 0;
	while (str[str_len] != '\0')
		++str_len;
	write(2, str, str_len);
}