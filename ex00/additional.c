/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:46:38 by onosul            #+#    #+#             */
/*   Updated: 2024/08/18 20:46:40 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_row_col_conflict(int row, int col, int num, t_puzzle *puzzle)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		if (puzzle->grid[row][i] == num || puzzle->grid[i][col] == num)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	reset_grid(int row, int col, t_puzzle *puzzle)
{
	puzzle->grid[row][col] = 0;
}

void	update_grid(int row, int col, int num, t_puzzle *puzzle)
{
	puzzle->grid[row][col] = num;
}
