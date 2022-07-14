/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 21:42:10 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 21:42:45 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	rra(t_stack *stack[2])
{
	void	*ptr;

	if (stack[0]->size == 0)
		return ;
	ptr = stack[0]->head->content;
	stack_pop_front(stack[0], NULL);
	stack_push_back(stack[0], ptr);
}
