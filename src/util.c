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

	//printf("d\n");
	dup = malloc(sizeof(char) * sl_strlen(s) + 1);
	//printf("s = %zu\n", sl_strlen(s));
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

int	count_value(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	recur_itoa(int n, char *ptr, int i)
{
	char	c;

	if (n < 0)
	{
		n *= -1;
		ptr[0] = '-';
		recur_itoa(n, ptr, i);
	}
	else if (n > 0)
	{
		c = n % 10;
		if (n / 10 > 0)
			recur_itoa(n / 10, ptr, i - 1);
		ptr[i] = '0' + c;
	}
	else if (n == 0)
		ptr[i] = '0';
}

char	*sl_itoa(int n)
{
	char	*ptr;
	size_t	count;

	if (n == -2147483648)
		return (sl_strdup("-2147483648"));
	count = count_value(n);
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (0);
	recur_itoa(n, ptr, count - 1);
	ptr[count] = 0;
	return (ptr);
}