/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:02:26 by kamanfo           #+#    #+#             */
/*   Updated: 2022/01/01 19:51:52 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_tab.h"

int	checkline(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	checkcol(char **col, int j)
{
	int	i;

	i = 0;
	while (col[i])
	{
		if (col[i][j] != '1' )
			return (0);
		i++;
	}
	return (1);
}

int	find_elem(char **map, char c)
{
	int	i;
	int	j;
	int	elem;

	i = 0;
	elem = 0;
	while (map[i])
	{
		j = 0;
		while (is_mapset(map[i][j]))
		{
			if (map[i][j] == c)
				elem++;
			j++;
		}
		i++;
	}
	if (!elem)
		return (0);
	return (elem);
}

int	check_wall(char **map, int height, int width)
{
	if (!checkline(map[0]) || !checkline(map[height - 1])
		|| !checkcol(map, 0) || !checkcol(map, width - 2))
		return (0);
	return (1);
}

int	check_rules(char **map, int height, int width)
{
	if (map == NULL)
		return (0);
	if (!check_wall(map, height, width))
		return (free_map(map), 0);
	if (!find_elem(map, 'E') || find_elem(map, 'P') != 1
		|| !find_elem(map, 'C'))
		return (free_map(map), 0);
	return (1);
}
