/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:13:20 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 01:26:10 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	while (stack[0]->size > 3)
		pb(stack);
	sort(stack, d);
	init_checks(stack);
	while (stack[1]->size > 0)
		reinsert_b(stack);
	if (*((int *)stack[0]->head->content) < 2)
		while (*((int *)stack[0]->tail->content) != 0)
			rra(stack);
	else
		while (*((int *)stack[0]->tail->content) != 0)
			ra(stack);
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
