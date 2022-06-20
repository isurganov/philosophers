/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:56:07 by spzona            #+#    #+#             */
/*   Updated: 2022/06/20 21:23:17 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_error(void)
{
	write(2, RED_COLOR, strlen(RED_COLOR));
	write(2, ERROR_MALLOC, strlen(ERROR_MALLOC));
	write(2, RESET_COLOR, strlen(RESET_COLOR));
	return (SUCCESS);
}

int	args_error(void)
{
	write(2, RED_COLOR, strlen(RED_COLOR));
	write(2, ERROR_ARGS, strlen(ERROR_ARGS));
	write(2, RESET_COLOR, strlen(RESET_COLOR));
	return (SUCCESS);
}

int	values_inputs_error(void)
{
	write(2, RED_COLOR, strlen(RED_COLOR));
	write(2, ERROR_VALUES_INPUTS, strlen(ERROR_VALUES_INPUTS));
	write(2, RESET_COLOR, strlen(RESET_COLOR));
	return (SUCCESS);
}
