/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:06:31 by spzona            #+#    #+#             */
/*   Updated: 2022/06/20 21:23:02 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_program	*program_init(void)
{
	t_program	*data;

	data = (t_program *)malloc(sizeof(t_program));
	if (data == NULL)
		return (NULL);
	memset(data, 0, sizeof(t_program));
	data->values_input = (t_values *)malloc(sizeof(t_values));
	memset(data->values_input, 0, sizeof(t_values));
	if (data->values_input == NULL)
		free_all(data, 0);
	return (data);
}

bool	philo_init(t_program *data, int i)
{
	data->philos = (t_philo *)ft_calloc(sizeof(t_philo),
			data->values_input->phil_num);
	if (data->philos == NULL)
		return (false);
	while (i < data->values_input->phil_num)
	{
		data->philos[i].id = i + 1;
		data->philos[i].values_input = data->values_input;
		data->philos[i].spectator = data->spectator;
		if (i == data->values_input->phil_num - 1)
		{
			data->philos[i].left_fork = &data->spectator->forks[i];
			data->philos[i].right_fork = &data->spectator->forks[0];
		}
		else
		{
			data->philos[i].left_fork = &data->spectator->forks[i];
			data->philos[i].right_fork = &data->spectator->forks[i + 1];
		}
		i++;
	}
	return (true);
}

bool	status_init(t_program *data)
{
	int	i;

	i = 0;
	data->spectator = (t_spectator *)ft_calloc(sizeof(t_spectator), 1);
	if (data->spectator != NULL)
	{
		if (pthread_mutex_init(&data->spectator->mute_print, NULL))
			return (false);
		data->spectator->forks = malloc(sizeof(pthread_mutex_t)
				* data->values_input->phil_num);
	}
	if (data->spectator == NULL || data->spectator->forks == NULL)
		return (false);
	while (i < data->values_input->phil_num)
	{
		if (pthread_mutex_init(&data->spectator->forks[i], NULL))
			return (false);
		i++;
	}
	return (true);
}
