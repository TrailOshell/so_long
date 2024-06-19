/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 17:06:46 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 21:10:38 by tsomchan         ###   ########.fr       */
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

void	write_value(char *msg, int int_val)
{
	char	*str;

	str = sl_strdup(msg);
	write(1, msg, sl_strlen(str));
	free(str);
	write(1, ": ", 2);
	str = sl_itoa(int_val);
	write(1, str, sl_strlen(str));
	free(str);
}