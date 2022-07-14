/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:54:23 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 21:55:18 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

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
int				has_duplicate(int *arr, int size);
void			msg_error(int error_code);
void			error_exit(int **arr, int error_code);
void			normalize(int **arr, int **arr_norm, int size);
void			ft_free(void *del);
void			*ft_malloc(size_t elem_cnt, size_t elem_size);
void			check_instructions(int *arr, int size, t_list *instructions);
void			check_args(int len, char **argv, int argc);
void			pa(t_stack *stack[2]);
void			pb(t_stack *stack[2]);
void			ra(t_stack *stack[2]);
void			rb(t_stack *stack[2]);
void			sa(t_stack *stack[2]);
void			rra(t_stack *stack[2]);
void			get_instructions(t_list **lst);

#endif