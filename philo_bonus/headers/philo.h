/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjettie <cjettie@21-school.ru>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 20:33:16 by cjettie           #+#    #+#             */
/*   Updated: 2021/09/10 20:33:29 by cjettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stddef.h>
# include <string.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <limits.h>
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_philo
{
	int				philo_id;
	int				color;
	long long int	l_meal;
	int				num_to_feed;
	sem_t			*d_t_acc;
	sem_t			*n_t_f_acc;
}					t_philo;

typedef struct s_comm_info
{
	long long int	start_t;
	struct timezone	t_zone;
	sem_t			*forks;
	sem_t			*death_sem;
	sem_t			*out_sem;
	sem_t			*p_out_sem;
	sem_t			*quit_sem;
	sem_t			*job_done_sem;
	sem_t			*start_sem;
	long long int	time_to_d;
	long long int	time_to_e;
	long long int	time_to_s;
	int				num_to_feed;
	int				start;
	int				philo_amnt;
	pthread_t		g_overseer;
}					t_comm_info;

typedef struct s_p_arg
{
	t_comm_info	c_info;
	t_philo		p;
	pthread_t	*tread_p;
}				t_p_arg;

void			put_err_msg(char *str);
int				ft_isdigit(int c);
void			philo_output(char *str, long long int curr_time, \
								t_p_arg *philo_arg);
void			overseer_output(long long int curr_time, t_p_arg *philo_arg);
int				init_common_info(t_comm_info *c_info_p, \
								int argc, char **argv);
void			init_philo(t_p_arg *p_arg_p, int counter);
pthread_mutex_t	*init_fork_array(int fork_amnt);
int				ft_atoi(const char *str);
void			start_simulation(t_comm_info *c_info, \
									t_p_arg *p_arg_p, int philo_amnt);
void			simulation(t_p_arg *p_arg_p);
long long int	ft_time(struct timezone *t_zone);
void			*philo_life_lim_start(void *p_a);
void			*philo_life_unlim_start(void *p_a);
void			p_overseer_unlim(t_comm_info *c_info, t_p_arg *p_a_p);
void			p_overseer_lim(t_comm_info *c_info, t_p_arg *p_a_p);
void			*destroy_philo_mutex(t_p_arg *p_arg_p, int counter);
void			set_l_meal(long long int *l_meal, t_p_arg *p_a, \
												struct timezone *t_z);
int				is_dead(t_p_arg *p_a, t_comm_info *c_info, \
												long long int time_to_d);
int				init_philo_acc_mutexes(t_p_arg *p_a);
void			wait_start(t_p_arg *p_a);
void			my_usleep(long long int	time_to_sleep);
int				clean(int status);
char			*ft_strdup(const char *s1);
int				ft_num_amount(int n);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *s);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
sem_t			*init_sem_philo(char const *str, int val);


#endif
