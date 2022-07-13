/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 00:26:44 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/12 00:38:56 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	msg_error(int error_code)
{
	write(STDERR_FILENO, "Error\n", 7);
	exit(error_code);
}

void	error_exit(int **arr, int **arr_norm, int error_code)
{
	write(STDERR_FILENO, "Error\n", 7);
	free(*arr);
	free(*arr_norm);
	exit(error_code);
}
