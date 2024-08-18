/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onosul <onosul@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 20:50:21 by onosul            #+#    #+#             */
/*   Updated: 2024/08/18 20:50:23 by onosul           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define SIZE 4
# include <unistd.h>

typedef struct s_puzzle
{
	int	grid[SIZE][SIZE];
	int	clues[4][SIZE];
}		t_puzzle;

void	parse_input(char *input, t_puzzle *puzzle);
void	initialize_grid(t_puzzle *puzzle);
void	print_grid(t_puzzle *puzzle);
char	*my_strtok(char *str, const char *delim);
int		my_atoi(const char *str);
int		solve(int row, int col, t_puzzle *puzzle);
int		check_row_col_conflict(int row, int col, int num, t_puzzle *puzzle);
void	reset_grid(int row, int col, t_puzzle *puzzle);
void	update_grid(int row, int col, int num, t_puzzle *puzzle);
int		count_visible(int *line);
int		check_row_clues(int row, t_puzzle *puzzle);
int		check_col_clues(int col, t_puzzle *puzzle);
int		is_valid(int row, int col, int num, t_puzzle *puzzle);

#endif
