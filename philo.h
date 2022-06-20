/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spzona <spzona@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 15:41:15 by spzona            #+#    #+#             */
/*   Updated: 2022/06/20 17:56:36 by spzona           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <string.h>

# define SUCCESS 0
# define FAILURE 1
# define BAD_RESULT -1
# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define PURPLE_COLOR "\033[0;35m"
# define RED_COLOR "\033[0;31m"
# define GREEN_COLOR "\033[0;32m"
# define RESET_COLOR "\033[1;33m"

# define ERROR_ARGS "*** Error *** Number of arguments is incorrect ***\n"
# define ERROR_VALUES_INPUTS "*** Error *** Incoming data is invalid ***\n"
# define ERROR_MALLOC "*** Error *** Failed to allocate memory ***\n"

# define DIED " \033[1;4;31m%6lu Philosofer %d  died\n\033[0m"
# define EATING " \033[0;32m%6lu %3d   is eating\n\033[0m"
# define SLEEPING " \033[0;34m%6lu %3d   is sleeping\n\033[0m"
# define THINKING " \033[0;35m%6lu %3d   is thinking\n\033[0m"
# define TAKEN_RIGHT_FORK " \033[0;37m%6lu %3d   has taken a right fork\n\033[0m"
# define TAKEN_LEFT_FORK " \033[0;37m%6lu %3d   has taken a left fork\n\033[0m"

typedef struct philos_values
{
	int				phil_num;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				add_eat;
	time_t			start;
}	t_values;

typedef struct s_spectator
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	mute_print;
}	t_spectator;

typedef struct s_philo
{
	int							id;
	pthread_mutex_t				*left_fork;
	pthread_mutex_t				*right_fork;
	pthread_t					thread_id;
	int							isdead;
	time_t						last_eat;
	int							count_eat;
	int							stop;
	struct philos_values		*values_input;
	struct s_spectator			*spectator;
}	t_philo;

typedef struct s_program
{
	struct philos_values		*values_input;
	struct s_philo				*philos;
	struct s_spectator			*spectator;
}	t_program;

bool		simulation(t_program *data);
void		*living(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
int			args_error(void);
int			malloc_error(void);
int			values_inputs_error(void);
t_program	*program_init(void);
bool		status_init(t_program *data);
bool		philo_init(t_program *data, int i);
int			strlen(char *str);
void		*ft_calloc(size_t count, size_t size);
int			free_all(t_program *data, int i);
bool		is_num(char *str);
void		ft_usleep(time_t time);
int			atoi_args(char *str);
time_t		do_newtime(time_t start);
bool		is_valid_data(int argc, char *argv[]);
bool		loading_data_values_input(t_values *values_inputs,
				int argc, char *argv[]);
void		draw_action(t_philo *philo, char *text, time_t time);
int			check_death(t_program *data, int i);
void		*check_pasta(t_program *data);

#endif
