/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:48:08 by spzona            #+#    #+#             */
/*   Updated: 2022/06/20 21:22:28 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	draw_action(t_philo *philo, char *text, time_t time)
{
	pthread_mutex_lock(&philo->spectator->mute_print);
	printf(text, time, philo->id);
	if (!philo->isdead)
		pthread_mutex_unlock(&philo->spectator->mute_print);
}

void	*check_pasta(t_program *data)
{
	int	i;
	int	everyone_is_full;

	while (1)
	{
		everyone_is_full = 0;
		i = 0;
		while (i < data->values_input->phil_num)
		{
			if (data->values_input->add_eat != -1 && \
			data->philos[i].count_eat >= data->values_input->add_eat)
			{
				everyone_is_full++;
				data->philos[i].stop = 1;
			}
			if (check_death(data, i))
				return (NULL);
			i++;
		}
		if (everyone_is_full == data->values_input->phil_num)
			return (NULL);
	}
	return (NULL);
}

int	check_death(t_program *data, int i)
{
	time_t	time_to_live;

	time_to_live = do_newtime(data->values_input->start)
		- data->philos[i].last_eat;
	if (time_to_live > data->values_input->die_time
		&& data->philos[i].stop != 1)
	{
		data->philos[i].isdead = 1;
		draw_action(&data->philos[i], DIED,
			do_newtime(data->values_input->start));
		return (FAILURE);
	}
	return (SUCCESS);
}
