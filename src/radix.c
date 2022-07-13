/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:37:09 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/12 00:42:41 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	final_move(t_stack *stack[2], int digit_move)
{
	int	cnt[2];

	cnt[0] = 0;
	cnt[1] = stack[0]->size;
	while (cnt[0]++ < cnt[1])
	{
		if ((*((int *)stack[0]->tail->content) >> digit_move) % 2 == 0)
			pb(stack);
		else
			ra(stack);
	}
	while (stack[1]->size > 0)
		pa(stack);
}

static void	sub(t_stack *stack[2], int digit_move, int cnt[2])
{
	cnt[1] = stack[1]->size;
	while (cnt[0]++ < cnt[1])
	{
		if ((*((int *)stack[1]->tail->content) >> digit_move) % 2)
			pa(stack);
		else
			rb(stack);
	}
	while (stack[1]->size > 0)
		pa(stack);
}

static void	normal_move(t_stack *stack[2], int digit_move)
{
	int	cnt[2];

	cnt[0] = 0;
	if (stack[0]->size > 0)
	{
		cnt[1] = stack[0]->size;
		while (cnt[0]++ < cnt[1])
		{
			if ((*((int *)stack[0]->tail->content) >> digit_move) % 2 == 0)
				pb(stack);
			else
				ra(stack);
		}
		while (stack[0]->size > 0)
			pb(stack);
	}
	else
		sub(stack, digit_move, cnt);
}

void	radix_move(t_stack *stack[2], int max_bit, int i)
{
	if (i == max_bit && i % 2)
		final_move(stack, i - 1);
	else
		normal_move(stack, i - 1);
}
