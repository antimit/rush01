/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:51:22 by onosul            #+#    #+#             */
/*   Updated: 2024/08/18 20:54:08 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	solve(int row, int col, t_puzzle *puzzle)
{
	int	num;

	if (row == SIZE)
		return (1);
	if (col == SIZE)
		return (solve(row + 1, 0, puzzle));
	num = 1;
	while (num <= SIZE)
	{
		if (is_valid(row, col, num, puzzle))
		{
			puzzle->grid[row][col] = num;
			if (solve(row, col + 1, puzzle))
				return (1);
			puzzle->grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

int	check_row_clues(int row, t_puzzle *puzzle)
{
	int	row_left[SIZE];
	int	row_right[SIZE];
	int	i;

	i = 0;
	while (i < SIZE)
	{
		row_left[i] = puzzle->grid[row][i];
		row_right[i] = puzzle->grid[row][SIZE - 1 - i];
		i++;
	}
	if (count_visible(row_left) != puzzle->clues[2][row]
		|| count_visible(row_right) != puzzle->clues[3][row])
	{
		return (0);
	}
	return (1);
}

int	check_col_clues(int col, t_puzzle *puzzle)
{
	int	col_up[SIZE];
	int	col_down[SIZE];
	int	i;

	i = 0;
	while (i < SIZE)
	{
		col_up[i] = puzzle->grid[i][col];
		col_down[i] = puzzle->grid[SIZE - 1 - i][col];
		i++;
	}
	if (count_visible(col_up) != puzzle->clues[0][col]
		|| count_visible(col_down) != puzzle->clues[1][col])
	{
		return (0);
	}
	return (1);
}

int	is_valid(int row, int col, int num, t_puzzle *puzzle)
{
	if (!check_row_col_conflict(row, col, num, puzzle))
	{
		return (0);
	}
	update_grid(row, col, num, puzzle);
	if (col == SIZE - 1 && !check_row_clues(row, puzzle))
	{
		reset_grid(row, col, puzzle);
		return (0);
	}
	if (row == SIZE - 1 && !check_col_clues(col, puzzle))
	{
		reset_grid(row, col, puzzle);
		return (0);
	}
	reset_grid(row, col, puzzle);
	return (1);
}
