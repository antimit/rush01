/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:51:14 by onosul            #+#    #+#             */
/*   Updated: 2024/08/18 20:51:16 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	my_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_input_format(char *input)
{
	int	i;

	while (*input)
	{
		if (!my_isdigit(*input) && *input != ' ')
		{
			write(1, "Error\n", 6);
			i = 1;
			return (i);
		}
		input++;
	}
	i = 0;
	return (i);
}

int	main(int argc, char **argv)
{
	t_puzzle	puzzle;
	int			i;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	i = check_input_format(argv[1]);
	if (i == 1)
		return (1);
	parse_input(argv[1], &puzzle);
	initialize_grid(&puzzle);
	if (solve(0, 0, &puzzle))
	{
		print_grid(&puzzle);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
