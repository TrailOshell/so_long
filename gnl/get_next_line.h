/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:56:50 by tsomchan          #+#    #+#             */
/*   Updated: 2023/09/19 14:56:51 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//	get_next_line.c
char	*get_next_line(int fd);
char	*read_next_line(int fd, char **store, char *buffer, size_t l_len);
void	get_store(char **store, int condition, char *section);
char	*join_line(char const *s1, char const *s2, size_t *l_len, size_t *b_nl);

//	get_next_line_utils.c
size_t	len_till_nl(const char *s);
char	*ft_strdup(const char *s1);

#endif
