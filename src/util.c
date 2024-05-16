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
	while (*(s++))
		len++;
	return (len);
}

char	*sl_strdup(char *s)
{
	char	*dup;
	int		i;

	printf("d\n");
	dup = malloc(sizeof(char) * sl_strlen(s) + 1);
	printf("s = %zu\n", sl_strlen(s));
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// printf("*s1 = \'%c\' \t *s2 = \'%c\'\n", *s1, *s2);
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

/*	int	sl_strrncmp(const char *s1, const char *s2, size_t n)
	size_t	len1;
	size_t	len2;

	len1 = sl_strlen(s1);
	len2 = sl_strlen(s2);

	while (n--)
		if (s1[len1] != s2[len2])
			return (s1[len1] - s2[len2]);
*/

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
		ptr[i++] = *(s1++);
	return (ptr);
}
