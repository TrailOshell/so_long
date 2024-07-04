/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_pathfinding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 21:26:59 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/04 21:27:02 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	debug_facing_step(int up, int down, int left, int right)
{
	int	c;

	c = set_next_step(up, down, left, right);
	write(1, &c, 1);
}

void	debug_pathfinding(int up, int down, int left, int right)
{
	write_value("up =", up);
	write(1, "\n", 1);
	write_value("down =", down);
	write(1, "\n", 1);
	write_value("left =", left);
	write(1, "\n", 1);
	write_value("right =", right);
	write(1, "\n", 1);
	write_color("facing ", GREEN);
	debug_facing_step(up, down, left, right);
	write(1, "\n", 1);
}
