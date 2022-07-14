/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:18:52 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 21:53:40 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	execute_instructions(t_stack *stack[2], t_list *instructions)
{
	t_list	*tmp;
	char	*instruction;

	tmp = instructions;
	while (tmp)
	{
		instruction = (char *)tmp->content;
		if (ft_strncmp(instruction, "pa", 2) == 0)
			pa(stack);
		else if (ft_strncmp(instruction, "pb", 2) == 0)
			pb(stack);
		else if (ft_strncmp(instruction, "ra", 2) == 0)
			ra(stack);
		else if (ft_strncmp(instruction, "rb", 2) == 0)
			rb(stack);
		else if (ft_strncmp(instruction, "sa", 2) == 0)
			sa(stack);
		else if (ft_strncmp(instruction, "rra", 3) == 0)
			rra(stack);
		tmp = tmp->next;
	}
}

static void	check_order(t_stack *stack[2])
{
	int				i;
	int				cur;
	int				next;
	t_double_list	*tmp;

	i = -1;
	if (stack[1]->size > 0)
	{
		ft_putstr_fd("\033[0;31mKO\033[0m\n", STDOUT_FILENO);
		return ;
	}
	tmp = stack[0]->tail;
	while (++i < stack[0]->size - 1)
	{
		cur = *((int *)tmp->content);
		next = *((int *)tmp->last->content);
		if (cur > next)
		{
			ft_putstr_fd("\033[0;31mKO\033[0m\n", STDOUT_FILENO);
			return ;
		}
		tmp = tmp->last;
	}
	ft_putstr_fd("\033[0;32mOK\033[0m\n", STDOUT_FILENO);
}

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

void	check_instructions(int *arr, int size, t_list *instructions)
{
	t_stack	*stack[2];

	build_stack(stack, arr, size);
	execute_instructions(stack, instructions);
	check_order(stack);
	free_stack();
	ft_lstclear(&instructions, free);
}
