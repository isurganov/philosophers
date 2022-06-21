/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:56:07 by spzona            #+#    #+#             */
/*   Updated: 2022/06/21 15:44:30 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	malloc_error(void)
{
	write(2, RED_COLOR, ft_strlen(RED_COLOR));
	write(2, ERROR_MALLOC, ft_strlen(ERROR_MALLOC));
	write(2, RESET_COLOR, ft_strlen(RESET_COLOR));
	return (SUCCESS);
}

int	args_error(void)
{
	write(2, RED_COLOR, ft_strlen(RED_COLOR));
	write(2, ERROR_ARGS, ft_strlen(ERROR_ARGS));
	write(2, RESET_COLOR, ft_strlen(RESET_COLOR));
	return (SUCCESS);
}

int	values_inputs_error(void)
{
	write(2, RED_COLOR, ft_strlen(RED_COLOR));
	write(2, ERROR_VALUES_INPUTS, ft_strlen(ERROR_VALUES_INPUTS));
	write(2, RESET_COLOR, ft_strlen(RESET_COLOR));
	return (SUCCESS);
}
