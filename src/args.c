/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:41:55 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 20:31:29 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_valid(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str) && *str != '-' && *str != ' ')
			return (0);
		str++;
	}
	return (1);
}

void	check_args(int len, char **argv, int argc)
{
	int	i;

	i = 0;
	if (argc == 1)
		exit(0);
	while (++i < len && argv[i])
		if (!is_valid(argv[i]))
			msg_error(1);
}
