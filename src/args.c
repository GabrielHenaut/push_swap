/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:41:55 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/12 00:42:13 by ghenaut-         ###   ########.fr       */
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

void	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc && argv[i])
		if (!is_valid(argv[i]))
			msg_error(1);
}
