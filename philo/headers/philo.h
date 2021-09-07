#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
#include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct		s_philo
{
	int				philo_id;
	int				color;
	pthread_mutex_t	*f_fork;
	pthread_mutex_t	*s_fork;
	long long int	l_meal;
	int				num_to_feed;

}					t_philo;

typedef struct		s_comm_info
{
	long long int	start_t;
	struct timezone	t_zone;
	pthread_mutex_t	death_mut;
	pthread_mutex_t	out_mut;
	pthread_mutex_t	p_out_mut;
	int				time_to_d;
	int				time_to_e;
	int				time_to_s;
	int				time_dealay;
	int				num_to_feed;
}					t_comm_info;

typedef struct	s_p_arg
{
	t_comm_info	*c_info;
	t_philo		p;
}				t_p_arg;

void			put_err_msg(char *str);
int				ft_isdigit(int c);
void			philo_output(char *str, long long int curr_time, \
								t_p_arg *philo_arg);
void			overseer_output(long long int curr_time, t_p_arg *philo_arg);
int				init_common_info(t_comm_info *c_info_p, \
								int argc, char **argv);
t_p_arg			*init_val(t_comm_info *c_info, int philo_amnt, \
					pthread_mutex_t *fork_arr);
pthread_mutex_t	*init_fork_array(int fork_amnt);
int				ft_atoi(const char *str);
void			start_simulation(t_comm_info *c_info, \
									t_p_arg *p_arg_p, int philo_amnt);
int				simulation(t_comm_info *c_info, \
							t_p_arg *p_arg_p, int philo_amnt);
long long int	ft_time(struct timezone *t_zone);
void			*philosopher_life(void *p_a);
void			p_overseer_unlim(t_comm_info *c_info, \
						t_p_arg *p_arg_p, int philo_amnt);
void			p_overseer_lim(t_comm_info *c_info, \
						t_p_arg **p_arg_pp, int philo_amnt);
#endif
