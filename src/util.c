/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:07:41 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 20:57:25 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	sl_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*(s++))
		len++;
	return (len);
}

char	*sl_strdup(char *s)
{
	char	*dup;
	int		i;

	dup = malloc(sizeof(char) * sl_strlen(s) + 1);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	sl_strrncmp(char *s1, char *s2, size_t n)
{
	while (*s1)
		s1++;
	while (*s2)
		s2++;
	while (n--)
		if (*(--s1) != *(--s2))
			return (*s1 - *s2);
	return (0);
}

char	*sl_strjoin(char *s1, char *s2)
{
	char	*ptr;
	size_t	size1;
	size_t	size2;
	int		i;

	if (!s1 || !s2)
		return (0);
	size1 = sl_strlen(s1);
	size2 = sl_strlen(s2);
	ptr = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (*s1)
		ptr[i++] = *(s1++);
	while (*s2)
		ptr[i++] = *(s2++);
	ptr[i] = '\0';
	return (ptr);
}
