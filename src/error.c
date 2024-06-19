/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:52:24 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 21:39:52 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_and_exit(char *msg, t_data *data)
{
	if (!msg || !*msg)
		write(1, "Error\n", 6);
	else
		write(1, msg, sl_strlen(msg));
	free_stuff(data);
	exit(0);
}
