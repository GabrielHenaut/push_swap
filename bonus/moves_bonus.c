/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:52:05 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 21:42:33 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	pa(t_stack *stack[2])
{
	void	*ptr;

	if (stack[1]->size > 0)
	{
		ptr = stack[1]->tail->content;
		stack_pop_back(stack[1], NULL);
		stack_push_back(stack[0], ptr);
	}
}

void	pb(t_stack *stack[2])
{
	void	*ptr;

	if (stack[0]->size > 0)
	{
		ptr = stack[0]->tail->content;
		stack_pop_back(stack[0], NULL);
		stack_push_back(stack[1], ptr);
	}
}

void	ra(t_stack *stack[2])
{
	void	*ptr;

	if (stack[0]->size == 0)
		return ;
	ptr = stack[0]->tail->content;
	stack_pop_back(stack[0], NULL);
	stack_push_front(stack[0], ptr);
}

void	rb(t_stack *stack[2])
{
	void	*ptr;

	if (stack[1]->size == 0)
		return ;
	ptr = stack[1]->tail->content;
	stack_pop_back(stack[1], NULL);
	stack_push_front(stack[1], ptr);
}

void	sa(t_stack *stack[2])
{
	void	*ptr[2];

	if (stack[0]->size > 1)
	{
		ptr[0] = stack[0]->tail->content;
		stack_pop_back(stack[0], NULL);
		ptr[1] = stack[0]->tail->content;
		stack_pop_back(stack[0], NULL);
		stack_push_back(stack[0], ptr[0]);
		stack_push_back(stack[0], ptr[1]);
	}
}
