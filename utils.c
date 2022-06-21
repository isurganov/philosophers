/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:48:25 by spzona            #+#    #+#             */
/*   Updated: 2022/06/21 15:44:30 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;
	size_t	i;
	size_t	n;

	i = 0;
	n = count * size;
	data = (void *)malloc(n);
	if (!data)
		return (NULL);
	else
		memset(data, 0, n);
	return (data);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

int	free_all(t_program *data, int i)
{
	if (data)
	{
		if (data->spectator)
		{
			while (data->spectator->forks && i < data->values_input->phil_num)
				pthread_mutex_destroy(&data->spectator->forks[i++]);
			pthread_mutex_destroy(&data->spectator->mute_print);
			free(data->spectator);
			data->spectator = NULL;
		}
		if (data->philos)
		{
			free(data->philos);
			data->philos = NULL;
		}
		if (data->values_input)
		{
			free(data->values_input);
			data->values_input = NULL;
		}
		free(data);
		data = NULL;
	}
	return (SUCCESS);
}

time_t	do_newtime(time_t start)
{
	struct timeval	tv;
	time_t			mls;
	time_t			time;

	gettimeofday(&tv, NULL);
	mls = tv.tv_sec * (time_t)1000 + tv.tv_usec / (time_t)1000;
	time = mls - start;
	return (time);
}

void	ft_usleep(time_t time)
{
	time_t	start;
	time_t	end;

	start = do_newtime(0);
	end = do_newtime(0) + time;
	while (start < end)
	{
		usleep(20);
		start = do_newtime(0);
	}
}
