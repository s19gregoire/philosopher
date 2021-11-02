/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:04:59 by gneve             #+#    #+#             */
/*   Updated: 2021/11/02 16:20:55 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	parser(int argc, char **argv, t_p *p)
{
	if ((argc == 5 || argc == 6) && numeric(argv, 0, 1))
	{
		p->a.total = ft_atoi(argv[1]);
		p->a.die = ft_atoi(argv[2]);
		p->a.eat = ft_atoi(argv[3]);
		p->a.sleep = ft_atoi(argv[4]);
		p->a.m_eat = -1;
		if (argc == 6)
			p->a.m_eat = ft_atoi(argv[5]);
		if (p->a.total <= 0 || p->a.die <= 0 || p->a.eat <= 0 \
			|| p->a.sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

void	init_mutex(t_p *p)
{
	pthread_mutex_init(&p->a.write_mutex, NULL);
	pthread_mutex_init(&p->a.dead, NULL);
	pthread_mutex_init(&p->a.time_eat, NULL);
	pthread_mutex_init(&p->a.finish, NULL);
}

int	initialize(t_p *p)
{
	int	i;

	i = 0;
	p->a.start_t = actual_time();
	p->a.stop = 0;
	p->a.nb_p_finish = 0;
	init_mutex(p);
	while (i < p->a.total)
	{
		p->ph[i].id = i + 1;
		p->ph[i].ms_eat = p->a.start_t;
		p->ph[i].nb_eat = 0;
		p->ph[i].finish = 0;
		p->ph[i].r_f = NULL;
		pthread_mutex_init(&p->ph[i].l_f, NULL);
		if (p->a.total == 1)
			return (1);
		if (i == p->a.total - 1)
			p->ph[i].r_f = &p->ph[0].l_f;
		else
			p->ph[i].r_f = &p->ph[i + 1].l_f;
		i++;
	}
	return (1);
}
