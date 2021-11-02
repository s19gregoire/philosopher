/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:54:01 by gneve             #+#    #+#             */
/*   Updated: 2021/11/02 16:20:33 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop(t_p *p)
{
	int	i;

	i = -1;
	while (!check_death2(p))
		ft_usleep(1);
	while (++i < p->a.total)
		pthread_join(p->ph[i].thread_id, NULL);
	pthread_mutex_destroy(&p->a.write_mutex);
	i = -1;
	while (++i < p->a.total)
		pthread_mutex_destroy(&p->ph[i].l_f);
	if (p->a.stop == 2)
		printf("Each philosopher ate %d time(s)\n", p->a.m_eat);
	free(p->ph);
}

int	main(int argc, char **argv)
{
	t_p		p;

	if (!(parser(argc, argv, &p)))
		return (ft_exit("Invalid Arguments\n"));
	p.ph = malloc(sizeof(t_philo) * p.a.total);
	if (!p.ph)
		return (0);
	if (!initialize(&p) || !threading(&p))
	{
		free(p.ph);
		return (0);
	}
	stop(&p);
}