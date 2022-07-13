/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 21:58:29 by yfu               #+#    #+#             */
/*   Updated: 2022/07/12 00:42:27 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_double_list	*double_list_init(void *ptr)
{
	t_double_list	*double_list;

	double_list = ft_malloc(1, sizeof(t_double_list));
	if (!double_list)
		return (NULL);
	double_list->content = ptr;
	double_list->next = NULL;
	double_list->last = NULL;
	return (double_list);
}

void	stack_clear(t_stack *stack, void (*f)(void*))
{
	while (stack->size)
		stack_pop_back(stack, f);
}

void	*ft_malloc(size_t elem_cnt, size_t elem_size)
{
	return (ft_memory(elem_cnt, elem_size, NULL, push));
}

void	ft_free(void *del)
{
	ft_memory(0U, 0U, del, pop);
}
