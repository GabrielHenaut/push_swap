/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:11:15 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/07/13 21:53:33 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

static int	check_overflow(char *str)
{
	if (ft_strnstr(str, "214748364", 9) && str[9] > '7')
		return (1);
	if (ft_strnstr(str, "-214748364", 10) && str[10] > '8')
		return (1);
	return (0);
}

static void	fill_array(int **arr, char *str, int i)
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
				error_exit(arr, 7);
			tmp = ft_atoi(str);
			counter = i - 1;
			(*arr)[counter] = tmp;
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

static void	get_array(int **arr, int argc, char **argv, int len)
{
	int	i;

	i = 0;
	*arr = (int *)malloc(len * sizeof(int));
	if (!*arr)
		msg_error(2);
	while (++i < argc)
		fill_array(arr, argv[i], i);
	if (has_duplicate(*arr, len))
		error_exit(arr, 3);
}

int	main(int argc, char **argv)
{
	int		*arr;
	int		len;
	t_list	*instructions;

	len = find_len(argv);
	check_args(len, argv, argc);
	get_array(&arr, argc, argv, len);
	get_instructions(&instructions);
	check_instructions(arr, len, instructions);
	free(arr);
}
