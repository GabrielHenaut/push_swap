/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:11:15 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/12 00:43:24 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	check_overflow(char *str)
{
	if (ft_strnstr(str, "214748364", 9) && str[9] > '7')
		return (1);
	if (ft_strnstr(str, "-214748364", 10) && str[10] > '8')
		return (1);
	return (0);
}

static void	fill_array(int **arr, int **arr_norm, char *str, int i)
{
	int	tmp;
	int	counter;

	while (*str)
	{
		if (*str == ' ')
			str++;
		else if (ft_isdigit(*str) || *str == '-' || *str == '+')
		{
			if (check_overflow(str))
				error_exit(arr, arr_norm, 7);
			tmp = ft_atoi(str);
			counter = i - 1;
			(*arr)[counter] = tmp;
			(*arr_norm)[counter] = tmp;
			i++;
			while (*str != ' ' && *str != '\0')
				str++;
		}
	}
}

static int	find_len(char **argv)
{
	int	len;
	int	i;
	int	j;

	len = 0;
	i = 0;
	while (argv[++i])
	{
		j = -1;
		len++;
		while (argv[i][++j])
			if (argv[i][j] == ' ')
				len++;
	}
	return (len);
}

static void	get_array(int **arr, int **arr_norm, int argc, char **argv)
{
	int	i;
	int	len;

	len = find_len(argv);
	i = 0;
	*arr = (int *)malloc(len * sizeof(int));
	if (!*arr)
		msg_error(2);
	*arr_norm = (int *)malloc(len * sizeof(int));
	if (!*arr_norm)
	{
		free(*arr);
		msg_error(3);
	}
	while (++i < argc)
		fill_array(arr, arr_norm, argv[i], i);
}

int	main(int argc, char **argv)
{
	int	*arr;
	int	*arr_norm;
	int	len;

	len = find_len(argv);
	check_args(len, argv);
	get_array(&arr, &arr_norm, argc, argv);
	normalize(&arr, &arr_norm, len);
	push_swap(arr_norm, len);
	free(arr);
	free(arr_norm);
}
