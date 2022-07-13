/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:46:06 by yfu               #+#    #+#             */
/*   Updated: 2022/07/11 15:16:45 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = ft_malloc(1, sizeof(t_stack));
	if (!stack)
		return (stack);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	stack_push_back(t_stack *stack, void *ptr)
{
	t_double_list	*temp;

	(stack->size)++;
	temp = double_list_init(ptr);
	if (!temp)
		return ;
	if (stack->size == 1)
	{
		stack->head = temp;
		stack->tail = temp;
		return ;
	}
	temp->last = stack->tail;
	stack->tail->next = temp;
	stack->tail = stack->tail->next;
}

void	stack_push_front(t_stack *stack, void *ptr)
{
	t_double_list	*temp;

	(stack->size)++;
	temp = double_list_init(ptr);
	if (!temp)
		return ;
	if (stack->size == 1)
	{
		stack->head = temp;
		stack->tail = temp;
		return ;
	}
	temp->next = stack->head;
	stack->head->last = temp;
	stack->head = stack->head->last;
}

void	stack_pop_back(t_stack *stack, void (*f)(void *))
{
	t_double_list	*temp;

	if (stack->size < 1 || !stack->tail)
		return ;
	(stack->size)--;
	temp = stack->tail;
	stack->tail = stack->tail->last;
	if (stack->tail)
		stack->tail->next = NULL;
	if (f)
		f(temp->content);
	ft_free(temp);
}

void	stack_pop_front(t_stack *stack, void (*f)(void*))
{
	t_double_list	*temp;

	if (stack->size < 1 || !stack->head)
		return ;
	(stack->size)--;
	temp = stack->head;
	stack->head = stack->head->next;
	if (stack->head)
		stack->head->last = NULL;
	if (f)
		f(temp->content);
	ft_free(temp);
}
