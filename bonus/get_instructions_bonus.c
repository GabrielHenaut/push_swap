/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_instructions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 19:49:57 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 20:59:49 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	get_instructions(t_list **lst)
{
	char	*line;
	t_list	*tmp;
	int		iteration;

	line = get_next_line(STDIN_FILENO);
	if (line)
		*lst = ft_lstnew(line);
	iteration = 0;
	while (line)
	{
		if (iteration > 0)
		{
			tmp = ft_lstnew(line);
			ft_lstadd_back(lst, tmp);
		}
		iteration++;
		line = get_next_line(STDIN_FILENO);
	}
}
