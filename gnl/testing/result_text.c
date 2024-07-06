/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:39:32 by tsomchan          #+#    #+#             */
/*   Updated: 2023/08/31 15:39:34 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

void	print_error_text(char *s)
{
	printcolor("| ", "blue");
	printcolor("ERROR!\n", "yellow");
	if (s && *s != 0)
	{
		printf(" ");
		printcolor(s, "black");
	}
}

void	print_result_text(char *s)
{
	printcolor("| ", "blue");
	printcolor(s, "black");
	printcolor(": ", "black");
}

void	print_compare_text(char *s)
{
	printcolor("| ", "blue");
	printcolor(s, "black");
}

void	print_test_line(char *s)
{
	printcolor("| ", "blue");
	printf("%s", s);
}

char	chr_rpc(unsigned int n, char c)
{
	ft_color("black");
	printf("Function %s is called\n", __func__);
	ft_color("reset");
	n = c;
	return (n);
}
