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

void	set_color(char *color)
{
	write(1, color, sl_strlen(color));
}

void	color_from_char(char c)
{
	if (c == '1')
		set_color(RED);
	else if (c == 'P')
		set_color(MAGENTA);
	else if (c == 'C')
		set_color(YELLOW);
	else if (c == 'E')
		set_color(GREEN);
	else if (c == '0')
		set_color(RESET);
	else
		set_color(MAGENTA);
}

void	write_grid(char **grid)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			c = grid[row][col++];
			color_from_char(c);
			write(1, &c, 1);
		}
		write(1, "\n", 1);
		row++;
	}
	set_color(RESET);
}

void	write_value(char *msg, int int_val)
{
	char	*str;

	set_color(BLUE);
	str = sl_strdup(msg);
	write(1, msg, sl_strlen(str));
	free(str);
	write(1, ": ", 2);
	set_color(RESET);
	str = sl_itoa(int_val);
	write(1, str, sl_strlen(str));
	free(str);
}

void	write_color(char *msg, char *color)
{
	char	*str;

	set_color(color);
	str = sl_strdup(msg);
	write(1, msg, sl_strlen(str));
	free(str);
	set_color(RESET);
}

/*
void	write_node(t_node *node)
{
	int	i;

	while (node)
	{
		i = 0;
		write_color("\"", BLUE);
		while (node->line[i])
		{
			if (node->line[i] == '\n')
				write_color("\\n", MAGENTA);
			else
				write(1, &node->line[i], 1);
			i++;
		}
		write_color("\"", BLUE);
		write(1, "\n", 1);
		node = node->next;
	}
}
*/