# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 14:03:47 by ghenaut-          #+#    #+#              #
#    Updated: 2022/07/13 01:26:38 by ghenaut-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all bonus clean fclean re

NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g3


LIBFT	= libft.a
IFT		= -Ilibft -Llibft -lft

SRCS	= 	push_swap.c \
			error.c \
			main.c \
			memory.c \
			normalize.c \
			stack.c \
			stack_utils.c \
			args.c \
			moves.c \
			radix.c \
			small_sort.c \
			small_sort_utils.c \

B_SRCS	=   

OBJSDIR	= ./obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})
B_OBJS	= $(addprefix ${OBJSDIR}/, ${B_SRCS:%.c=%.o})

all: ${NAME}
# @make clean

bonus: ${NAME}_bonus
	@make clean

${NAME}: ${OBJSDIR} ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${IFT} -o $@

${NAME}_bonus: ${OBJSDIR} ${B_OBJS}
	@${CC} ${CFLAGS} ${B_OBJS} ${IFT} -o $@

${OBJSDIR}:
	@mkdir -p $@

${OBJSDIR}/%.o: src/%.c includes/push_swap.h Makefile ${LIBFT}
	@${CC} ${CFLAGS} -c $< -o $@

${OBJSDIR}/%.o: bonus/%.c includes/push_swap_bonus.h Makefile ${LIBFT}
	@${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
	@${MAKE} -C libft/

clean:
	@${MAKE} clean -C libft
	@rm -rf ${OBJSDIR}

fclean: clean
	@${MAKE} fclean -C libft
	@rm -rf ${NAME} ${NAME}_bonus

re: fclean all

