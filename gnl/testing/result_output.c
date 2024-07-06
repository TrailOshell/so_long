/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:08:59 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/07 16:06:46 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myft.h"

//	Showing results
int	find_test(char **argv, char *part, char *test)
{
	if (argv[1] == 0 || strcmp(argv[1], part) == 0)
		return (1);
	while (*argv != 0)
	{
		if (strcmp(*argv, test) == 0)
			return (1);
		argv++;
	}
	return (0);
}

void	print_null(char *s, unsigned int n)
{
	printf("\"");
	while (n > 0)
	{
		if (*s == 0)
			printf(" \\0 ");
		else
			printf("%c", *s);
		s++;
		n--;
	}
	printf("\"");
	printf("\n");
}

void	print_arr(int *arr, int size)
{
	while (size > 0)
	{
		printf("%d ", *arr);
		arr++;
		size--;
	}
}

void	print_str_arr(char **arr, int size)
{
	if (arr)
	{
		printf("{");
		while (size > 0)
		{
			printf("\"%s\"", *arr++);
			if (size != 1)
				printf(" ");
			size--;
		}
		printf("}");
	}
	else
		printf("\"(null)\"");
	printf("\n");
}
