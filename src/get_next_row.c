/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_row.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:09:31 by tsomchan          #+#    #+#             */
/*   Updated: 2024/05/17 16:09:33 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_col(t_data *data, int len)
{
	if (len <= 0)
		return (0);
	if (data->map->n_col == 0)
		data->map->n_col = len;
	else if (len != data->map->n_col)
		return (0);
	return (1);
}

/*	int	check_map_col(t_data *data, char *line, int len)
	if (data->map->n_row == 0)
		while (line)
			if ((*line)++ != 1)
				return (0);
*/

int	check_map_row(char *line, int len)
{
	if (line[0] != '1' || line[len - 1] != '1')
		return (0);
	while (len--)
		if (isvalidchar(*(line++)) == 0)
			return (0);
	return (1);
}

void	add_line(t_node **node, char *line)
{
	t_node	*new;
	t_node	*tmp;
	int		i;
	int		len;

	new = malloc(sizeof(t_node));
	len = sl_strlen(line);
	if (line[len - 1] == '\n')
		len--;
	//printf("len = %d\n", len);
	new->line = malloc(sizeof(char) * len + 1);
	i = 0;
	while (len--)
	{
		new->line[i] = line[i];
		i++;
	}
	new->line[i] = '\0';
	new->next = NULL;
	//printf("--- adding ---\n");
	//printf("add line = %s\n", new->line);
	if (!*node)
	{
		*node = new;
		//printf("add first node->line = %s\n", (*node)->line);
		return ;
	}
	//printf("--- debug ---\n");
	//printf("node->line = %s\n", (*node)->line);
	tmp = *node;
	while (tmp->next)
	{
		//printf("node->next->line = %s\n", (*node)->next->line);
		tmp = tmp->next;
	}
	tmp->next = new;
	//printf("add node->next->line = %s\n", (*node)->next->line);
}

void	get_next_row(t_data *data, int fd, char *line)
{
	int		len;

	while (1)
	{
		line = get_next_line(fd);
		//printf("line = %s\n", line);
		if (!line)
			break ;
		len = sl_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		//printf("len = %d\n", len);
		if (check_map_col(data, len) == 0 || check_map_row(line, len) == 0)
			error_and_exit();
		add_line(&data->node, line);
		//if (data->node)
		//	printf("data->node = true\n");
		//printf("data->node = %s\n", data->node->line);
		free(line);
		data->map->n_row++;
	}
}
