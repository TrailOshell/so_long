/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:06:46 by tsomchan          #+#    #+#             */
/*   Updated: 2024/05/17 17:06:51 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_grid(char **grid)
{
	int	row;
	int	col;

	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
			write(1, &(grid[row][col++]), 1);
		write(1, "\n", 1);
		row++;
	}
}
