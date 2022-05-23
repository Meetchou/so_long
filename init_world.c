/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:06:24 by kamanfo           #+#    #+#             */
/*   Updated: 2022/01/01 20:05:43 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_tab.h"

t_player	*init_player(int i, int j)
{
	t_player	*player;
	t_Coord		coord;

	player = (t_player *)malloc(sizeof(t_player));
	coord.y = i;
	coord.x = j;
	player->coord = coord;
	player->dir = -1;
	return (player);
}

void	init_images(t_world *world)
{
	init_imageset(world);
	init_anim_player(world);
	init_anim_enemy(world);
	init_anim_chest(world);
}

t_world	init_world(char **map, t_mlx *mlx)
{
	int		i;
	int		j;
	t_world	world;

	i = 0;
	world.nb_item = 0;
	while (map[i])
	{
		j = 0;
		while (is_mapset(map[i][j]))
		{
			if (map[i][j] == 'P')
				world.player = init_player(i, j);
			if (map[i][j] == 'C')
				world.nb_item++;
			j++;
		}
		i++;
	}
	world.map = map;
	world.mlx = mlx;
	world.count_move = 0;
	init_images(&world);
	return (world);
}
