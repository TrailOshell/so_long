/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:07:41 by tsomchan          #+#    #+#             */
/*   Updated: 2024/05/09 19:07:43 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	sl_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s++)
		len++;
	return (0);
}

int	sl_strrncmp(const char *s1, const char *s2, size_t n)
{
	while (s1)
		s1++;
	while (s2)
		s2++;
	while (n--)
		if (*(--s1) != *(--s2))
			return (*s1 - *s2);
	return (0);
}

/*	int	sl_strrncmp(const char *s1, const char *s2, size_t n)
	size_t	len1;
	size_t	len2;

	len1 = sl_strlen(s1);
	len2 = sl_strlen(s2);

	while (n--)
		if (s1[len1] != s2[len2])
			return (s1[len1] - s2[len2]);
*/