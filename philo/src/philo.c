#include "philo.h"

int		check_args(int argc, char **argv)
{
	int		str_pos;

	--argc;
	++argv;
	if (argc < 4 || argc > 5)
	{
		put_err_msg("wrong argument amount\n");
		return (1);
	}
	str_pos = 0;
	while (argc > 0)
	{
		while ((*argv)[str_pos] != '\0')
		{
			if (ft_isdigit((*argv)[str_pos]) == 0)
			{
				put_err_msg("numeric argument required\n");
				return (1);
			}
			++str_pos;
		}
		--argc;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	if (check_args(argc++, argv++) != 0)
		return (1);

	return (0);
}