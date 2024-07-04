/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:23:55 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 21:03:30 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isvalidchar(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C' || c == 'T')
		return (1);
	else if (c == '\n')
		return (1);
	return (0);
}

int	iswalkable(char c)
{
	if (c == '0' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

int	ispatrolable(char c)
{
	if (c == '0' || c == 'C' || c == 'P' || c == 'T')
		return (1);
	return (0);
}
