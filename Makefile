# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spzona <spzona@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 15:53:07 by spzona            #+#    #+#              #
#    Updated: 2022/06/21 18:18:38 by spzona           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

HEADER		=	philo.h

FLAGS		=	-Wall -Wextra -Werror -pthread

SRC			=	actions.c		args.c		errors.c \
				init.c			philo.c		process.c \
				utils.c

OBJ			=	${SRC:.c=.o}
OBJ_D		=	${patsubst %.c,%.d,${SRC}}

all			:	${NAME}
	@echo "Philos are ready to roll!"

${NAME}		:	${OBJ}

%.o			:	%.c	${HEADER}
	@cc ${FLAGS} -O2 -c $< -o $@ -MD

include ${wildcard ${OBJ_D}}

clean		:
	@rm -f ${OBJ} ${OBJ_D}
	@echo "OBJS are dead"

fclean		:	clean
	@rm -f ${NAME}
	@echo "Philos are dead"

re			:	fclean all

.PHONY	:	all re clean fclean