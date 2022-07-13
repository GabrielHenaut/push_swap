/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:56:02 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 01:18:38 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"

//./tester.sh ../ 500 10 && ./tester.sh ../ 100 10 && ./tester.sh ../ 50 10 && ./tester.sh ../ 10 10 && ./tester.sh ../ 5 10 && ./tester.sh ../ 4 10 && ./tester.sh ../ 3 10 && ./tester.sh ../ 2 10 && ./tester.sh ../ 1 10

typedef struct s_double_list
{
	void					*content;
	struct s_double_list	*next;
	struct s_double_list	*last;
}				t_double_list;

typedef struct s_stack
{
	struct s_double_list	*head;
	struct s_double_list	*tail;
	int						size;
}				t_stack;

typedef enum e_memory
{
	push,
	pop,
	clear
}				t_memory;

typedef struct s_digits
{
	int	top;
	int	mid;
	int	bottom;
}				t_digits;

void			stack_clear(t_stack *stack, void (*f)(void*));
t_double_list	*double_list_init(void *ptr);
void			stack_push_back(t_stack *stack, void *ptr);
void			stack_push_front(t_stack *stack, void *ptr);
void			stack_pop_back(t_stack *stack, void (*f)(void*));
void			stack_pop_front(t_stack *stack, void (*f)(void*));
t_stack			*stack_init(void);
void			*ft_memory(size_t elem_cnt,
					size_t elem_size, void *del, t_memory type);
void			msg_error(int error_code);
void			error_exit(int **arr, int **arr_norm, int error_code);
void			normalize(int **arr, int **arr_norm, int size);
void			ft_free(void *del);
void			*ft_malloc(size_t elem_cnt, size_t elem_size);
void			push_swap(int *arr, int size);
void			check_args(int argc, char **argv);
void			print_debug(t_stack *a, t_stack *b, size_t size);
void			sort_small(t_stack *stack[2]);
void 			radix_move(t_stack *stack[2], int max_bit, int i);
void			pa(t_stack *stack[2]);
void			pb(t_stack *stack[2]);
void			ra(t_stack *stack[2]);
void			rb(t_stack *stack[2]);
void			sa(t_stack *stack[2]);
void			rra(t_stack *stack[2]);
void			get_digits(t_stack *stack, t_digits *digits, int size);
void			init_checks(t_stack *stack[2]);
void	reinsert_b(t_stack *stack[2]);


void print_debug(t_stack *a, t_stack *b, size_t size);


#endif