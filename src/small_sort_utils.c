/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:32:26 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 01:25:56 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_digits(t_stack *stack, t_digits *digits, int size)
{
	if (size > 2)
	{
		digits->top = *((int *)stack->head->next->next->content);
		digits->bottom = *((int *)stack->head->content);
		digits->mid = *((int *)stack->head->next->content);
	}
	else
	{
		digits->top = *((int *)stack->tail->content);
		digits->bottom = *((int *)stack->head->content);
	}
}

void	reinsert_b(t_stack *stack[2])
{
	int	tail_a;
	int	tail_b;

	tail_a = *((int *)stack[0]->tail->content);
	tail_b = *((int *)stack[1]->tail->content);
	while (tail_a - 1 != tail_b)
	{
		if (tail_a == 0 && tail_b == (stack[0]->size + stack[1]->size) - 1)
			break ;
		if (tail_b - tail_a > 2)
			rra(stack);
		else
			ra(stack);
		tail_a = *((int *)stack[0]->tail->content);
		tail_b = *((int *)stack[1]->tail->content);
	}
	pa(stack);
}

void	init_checks(t_stack *stack[2])
{
	int	head;
	int	tail;

	head = *((int *)stack[1]->head->content);
	tail = *((int *)stack[1]->tail->content);
	if (tail == 0)
		pa(stack);
	else if (head == 0)
	{
		rb(stack);
		pa(stack);
	}
	if (stack[1]->size > 0 && head > tail)
		rb(stack);
}

void	rra(t_stack *stack[2])
{
	void	*ptr;

	if (stack[0]->size == 0)
		return ;
	ptr = stack[0]->head->content;
	stack_pop_front(stack[0], NULL);
	stack_push_back(stack[0], ptr);
	ft_putstr_fd("rra\n", STDOUT_FILENO);
}
