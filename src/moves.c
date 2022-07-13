/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:52:05 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 01:25:03 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *stack[2])
{
	void	*ptr;

	if (stack[1]->size > 0)
	{
		ptr = stack[1]->tail->content;
		stack_pop_back(stack[1], NULL);
		stack_push_back(stack[0], ptr);
	}
	ft_putstr_fd("pa\n", STDOUT_FILENO);
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
	ft_putstr_fd("pb\n", STDOUT_FILENO);
}

void	ra(t_stack *stack[2])
{
	void	*ptr;

	if (stack[0]->size == 0)
		return ;
	ptr = stack[0]->tail->content;
	stack_pop_back(stack[0], NULL);
	stack_push_front(stack[0], ptr);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
}

void	rb(t_stack *stack[2])
{
	void	*ptr;

	if (stack[1]->size == 0)
		return ;
	ptr = stack[1]->tail->content;
	stack_pop_back(stack[1], NULL);
	stack_push_front(stack[1], ptr);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
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
	ft_putstr_fd("sa\n", STDOUT_FILENO);
}
