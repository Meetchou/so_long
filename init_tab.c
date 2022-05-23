/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:30:19 by kamanfo           #+#    #+#             */
/*   Updated: 2022/01/01 19:18:09 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_tab.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
}

char	**initialize_tmap(t_map *lmap)
{
	char	**tab;
	int		i;
	int		len;

	if (!lmap)
		print_error(NULL);
	len = lst_len(lmap);
	tab = (char **)malloc((len + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = ft_strdup(lmap->line);
		if (!tab[i])
		{
			return (free_map(tab), NULL);
		}
		i++;
		lmap = lmap->next;
	}
	tab[i] = NULL;
	if (!verif_map(tab))
		return (free_map(tab), NULL);
	return (tab);
}

int	verif_list(t_map *lmap)
{
	t_map	*tmp;

	tmp = lmap;
	if (lst_len(lmap) < 3)
		return (0);
	while (tmp->next)
	{
		if (tmp->len != tmp->next->len || tmp->len < 4)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_map	*parse_map(int fd)
{
	char	*line;
	t_map	*lmap;
	size_t	len;
	int		i;

	if (fd == -1)
		print_error(NULL);
	i = 0;
	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	lmap = creat_lmap_elem(line, len);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		push_last_elem(&lmap, line, ft_strlen(line));
	}
	if (!verif_list(lmap))
		return (ft_lstclear(&lmap), NULL);
	return (lmap);
}
