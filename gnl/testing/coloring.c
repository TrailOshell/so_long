/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:38:49 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 14:40:10 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "myft.h"

void	ft_color(char *colorstr)
{
	char	*set;
	char	*color;

	color = strdup(colorstr);
	if (strcmp(color, "black") == 0)
		set = "[1;30m";
	else if (strcmp(color, "red") == 0)
		set = "[1;31m";
	else if (strcmp(color, "green") == 0)
		set = "[1;32m";
	else if (strcmp(color, "yellow") == 0)
		set = "[1;33m";
	else if (strcmp(color, "blue") == 0)
		set = "[1;34m";
	else if (strcmp(color, "purple") == 0)
		set = "[1;35m";
	else if (strcmp(color, "cyan") == 0)
		set = "[1;36m";
	else if (strcmp(color, "white") == 0)
		set = "[1;37m";
	else if (strcmp(color, "reset") == 0)
		set = "[0m";
	else
		set = "[0m";
	printf("\033%s", set);
	free(color);
}

void	printcolor(char *s, char *color)
{
	ft_color(color);
	printf("%s", s);
	ft_color("reset");
}
