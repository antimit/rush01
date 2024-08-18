/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:51:06 by onosul            #+#    #+#             */
/*   Updated: 2024/08/18 20:51:08 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	parse_input(char *input, t_puzzle *puzzle)
{
	int		index;
	char	*token;

	index = 0;
	token = my_strtok(input, " ");
	while (token != NULL)
	{
		puzzle->clues[index / SIZE][index % SIZE] = my_atoi(token);
		index++;
		token = my_strtok(NULL, " ");
	}
}

void	initialize_grid(t_puzzle *puzzle)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			puzzle->grid[i][j] = 0;
			j++;
		}
		i++;
	}
}
