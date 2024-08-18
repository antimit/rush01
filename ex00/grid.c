/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:10 by onosul            #+#    #+#             */
/*   Updated: 2024/08/18 20:50:12 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <unistd.h>

int	count_visible(int *line)
{
	int	max_height;
	int	visible_count;
	int	i;

	max_height = 0;
	visible_count = 0;
	i = 0;
	while (i < SIZE)
	{
		if (line[i] > max_height)
		{
			max_height = line[i];
			visible_count++;
		}
		i++;
	}
	return (visible_count);
}

void	print_char(char c)
{
	write(1, &c, 1);
}

void	print_grid(t_puzzle *puzzle)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			c = puzzle->grid[i][j] + '0';
			print_char(c);
			if (j < SIZE - 1)
				print_char(' ');
			j++;
		}
		print_char('\n');
		i++;
	}
}
