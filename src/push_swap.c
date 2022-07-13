/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:18:52 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/12 20:55:08 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	build_stack(t_stack *stack[2], int *arr, int size)
{
	int		i;

	i = -1;
	stack[0] = stack_init();
	stack[1] = stack_init();
	while (++i < size)
		stack_push_front(stack[0], arr + i);
}

static void	free_stack(void)
{
	ft_memory(0, 0, NULL, clear);
}

void	push_swap(int *arr, int size)
{
	t_stack	*stack[2];
	int		max_bit;
	int		i;

	i = 0;
	build_stack(stack, arr, size);
	if (size > 5)
	{
		max_bit = 0;
		while ((1 << max_bit) < stack[0]->size)
			++max_bit;
		while (i++ < max_bit)
			radix_move(stack, max_bit, i);  
	}
	else
		sort_small(stack);
	free_stack();
}
