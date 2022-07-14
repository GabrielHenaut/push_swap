/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:26:44 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 20:14:47 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	msg_error(int error_code)
{
	write(STDERR_FILENO, "Error\n", 7);
	exit(error_code);
}

void	error_exit(int **arr, int error_code)
{
	write(STDERR_FILENO, "Error\n", 7);
	free(*arr);
	exit(error_code);
}
