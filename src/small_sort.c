/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:13:20 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 00:58:27 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	get_digits(t_stack *stack, t_digits *digits, int size)
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

static void	sort(t_stack *stack[2], t_digits d)
{
	if (d.top < d.mid && d.mid < d.bottom && d.top < d.bottom)
		return ;
	else if (d.top > d.mid && d.mid < d.bottom && d.top < d.bottom)
		sa(stack);
	else if (d.top < d.mid && d.mid > d.bottom && d.top > d.bottom)
		rra(stack);
	else if (d.top > d.mid && d.mid < d.bottom && d.top > d.bottom)
		ra(stack);
	else if (d.top < d.mid && d.mid > d.bottom && d.top < d.bottom)
	{
		sa(stack);
		ra(stack);
	}
	else if (d.top > d.mid && d.mid > d.bottom && d.top > d.bottom)
	{
		sa(stack);
		rra(stack);
	}
}

static void	sort_complex(t_stack *stack[2], t_digits d)
{
	int c = 0;
	while(stack[0]->size > 3)
		pb(stack);
	sort(stack, d);
	// print_debug(stack[0], stack[1], stack[0]->size);
	if (*((int *)stack[1]->tail->content) == 0)
		pa(stack);
	else if (*((int *)stack[1]->head->content) == 0)
	{
		rb(stack);
		pa(stack);
	}
	if (stack[1]->size > 0 && *((int *)stack[1]->head->content) > *((int *)stack[1]->tail->content))
		rb(stack);
	while (stack[1]->size > 0)
	{
		// printf("bottom %d top %d\n", *((int *)stack[1]->head->content), *((int *)stack[1]->tail->content));
		while(*((int *)stack[0]->tail->content) - 1 != *((int *)stack[1]->tail->content))// && c < 3)
		{
			if (*((int *)stack[0]->tail->content) == 0 && *((int *)stack[1]->tail->content) == (stack[0]->size + stack[1]->size) - 1)
				break ;
			// printf("top %d top B %d\n", *((int *)stack[0]->head->content), *((int *)stack[1]->head->content));
			// print_debug(stack[0], stack[1], stack[0]->size);
			if (*((int *)stack[1]->tail->content) - *((int *)stack[0]->tail->content) > 2)
				rra(stack);
			else
				ra(stack);
			// print_debug(stack[0], stack[1], stack[0]->size);
			c++;
		}
		pa(stack);
		// print_debug(stack[0], stack[1], stack[0]->size);
	}
	if (*((int *)stack[0]->head->content) < 2)
		while (*((int *)stack[0]->tail->content) != 0)
			rra(stack);
	else
		while (*((int *)stack[0]->tail->content) != 0)
			ra(stack);
	// print_debug(stack[0], stack[1], stack[0]->size);
}

void	sort_small(t_stack *stack[2])
{
	t_digits	d;

	get_digits(stack[0], &d, stack[0]->size);
	if (stack[0]->size == 2 && d.top > d.bottom)
		sa(stack);
	else if (stack[0]->size == 3)
		sort(stack, d);
	else if (stack[0]->size > 3)
		sort_complex(stack, d);
}