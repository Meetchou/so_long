/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:30:30 by kamanfo           #+#    #+#             */
/*   Updated: 2021/12/28 20:34:27 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_tab.h"

t_map	*creat_lmap_elem(char *line, size_t len)
{
	t_map	*tmp;

	tmp = (t_map *)malloc(sizeof(t_map));
	if (!tmp)
		return (NULL);
	tmp->line = line;
	tmp->len = len;
	tmp->next = NULL;
	return (tmp);
}

int	push_last_elem(t_map **lmap, char *line, size_t len)
{	
	t_map	*tmp;
	t_map	*elem;

	tmp = NULL;
	if (!lmap)
		return (0);
	elem = creat_lmap_elem(line, len);
	if (!(*lmap))
		*lmap = elem;
	else
	{
		tmp = *lmap;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	return (1);
}

int	lst_len(t_map *lmap)
{
	t_map	*tmp;
	int		i;

	if (!lmap)
		return (0);
	tmp = lmap;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	is_mapset(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'M'
		|| c == 'E' || c == 'P' || c == 'F')
		return (1);
	return (0);
}

int	verif_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			if (!is_mapset(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
