/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 10:43:39 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/12 00:39:19 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	has_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
			if (arr[i] == arr[j])
				return (1);
	}
	return (0);
}

int	binary_search(int *arr, int arr_size, int target)
{
	int	lb;
	int	ub;
	int	mid;

	lb = -1;
	ub = arr_size;
	while (ub - lb > 1)
	{
		mid = (ub + lb) / 2;
		if (arr[mid] < target)
			lb = mid;
		else if (arr[mid] > target)
			ub = mid;
		else
			return (mid);
	}
	return (-1);
}

void	normalize(int **arr, int **arr_norm, int size)
{
	int	i;

	quicksort(*arr, size);
	i = -1;
	while (++i < size)
		(*arr_norm)[i] = binary_search(*arr, size, (*arr_norm)[i]);
	if (has_duplicate(*arr, size))
	{
		free(*arr);
		free(*arr_norm);
		msg_error(3);
	}
}
