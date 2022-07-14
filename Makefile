# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/01 14:03:47 by ghenaut-          #+#    #+#              #
#    Updated: 2022/07/13 21:56:41 by ghenaut-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	= all bonus clean fclean re

NAME		= push_swap
NAME_BONUS	= checker
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

B_SRCS	=   check_instructions_bonus.c \
			args_bonus.c \
			error_bonus.c \
			get_instructions_bonus.c \
			main_bonus.c \
			memory_bonus.c \
			moves_bonus.c \
			moves2_bonus.c \
			stack_bonus.c \
			stack_utils_bonus.c \

OBJSDIR	= ./obj
B_OBJSDIR	= ./obj_bonus
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:%.c=%.o})
B_OBJS	= $(addprefix ${B_OBJSDIR}/, ${B_SRCS:%.c=%.o})

all: ${NAME}

bonus: ${NAME_BONUS}

${NAME}: ${OBJSDIR} ${OBJS}
	@${CC} ${CFLAGS} ${OBJS} ${IFT} -o $@

${NAME_BONUS}: ${NAME} ${B_OBJSDIR} ${B_OBJS}
	@${CC} ${CFLAGS} ${B_OBJS} ${IFT} -o $@

${OBJSDIR}:
	@mkdir -p $@

${OBJSDIR}/%.o: src/%.c includes/push_swap.h Makefile ${LIBFT}
	@${CC} ${CFLAGS} -c $< -o $@

${B_OBJSDIR}:
	@mkdir -p $@

${B_OBJSDIR}/%.o: bonus/%.c includes/push_swap_bonus.h includes/push_swap.h Makefile ${LIBFT}
	@${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
	@${MAKE} -C libft/

clean:
	@${MAKE} clean -C libft
	@rm -rf ${OBJSDIR}
	@rm -rf ${B_OBJSDIR}

fclean: clean
	@${MAKE} fclean -C libft
	@rm -rf ${NAME} ${NAME_BONUS}

re: fclean all

