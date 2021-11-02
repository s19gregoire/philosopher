/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:44:41 by gneve             #+#    #+#             */
/*   Updated: 2021/11/02 16:20:42 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_arg
{
	int						total;
	int						die;
	int						eat;
	int						sleep;
	int						m_eat;
	long int				start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
	int						nb_p_finish;
	int						stop;
}							t_arg;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*r_f;
	pthread_mutex_t			l_f;
	t_arg					*pa;
	long int				ms_eat;
	unsigned int			nb_eat;
	int						finish;
}							t_philo;

typedef struct s_p
{
	t_philo					*ph;
	t_arg					a;
}		t_p;

int	check_death2(t_p *p);
void	*is_dead(void	*data);
int	ft_exit(char *str);
int	ft_atoi(const char *str);
int	numeric(char **argv, int i, int j);
int	initialize(t_p *p);
int	parser(int argc, char **argv, t_p *p);
int	threading(t_p *p);
void	activity(t_philo *ph);
void	write_status(char *str, t_philo *ph);
int	check_death(t_philo *ph, int i);
void	ft_usleep(long int time_in_ms);
long int	actual_time(void);
size_t	ft_strlen(const char *str);
#endif