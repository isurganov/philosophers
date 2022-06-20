/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:42:16 by spzona            #+#    #+#             */
/*   Updated: 2022/06/20 17:56:40 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_program	*program;

	if (argc != 6 && argc != 5)
		return (args_error() + FAILURE);
	program = program_init();
	if (program == NULL)
		return (malloc_error() + free_all(program, 0) + FAILURE);
	if (loading_data_values_input(program->values_input, argc, argv) == FAILURE)
		return (values_inputs_error() + free_all(program, 0) + FAILURE);
	if (status_init(program) == false)
		return (malloc_error() + free_all(program, 0) + FAILURE);
	if (philo_init(program, 0) == false)
		return (malloc_error() + free_all(program, 0) + FAILURE);
	if (simulation(program) == false)
		return (malloc_error() + free_all(program, 0) + FAILURE);
	free_all(program, 0);
	return (SUCCESS);
}
