/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:48:12 by kamanfo           #+#    #+#             */
/*   Updated: 2021/12/28 14:44:05 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_tab.h"

void	ft_put_image(t_world world, t_image image, int i, int j)
{
	mlx_put_image_to_window(world.mlx->mlx, world.mlx->win,
		image.image, j * world.imgset[0].img_height,
		i * world.imgset[0].img_width);
}

void	player_move(t_world *world, int dir, int y, int x)
{
	printf("Nombres de pas : %d\n", (++(world->count_move)));
	if (is_item(world->map[y][x]))
		world->nb_item--;
	world->player->dir = dir;
	world->map[world->player->coord.y][world->player->coord.x] = '0';
	world->player->coord.y = y;
	world->player->coord.x = x;
	world->map[world->player->coord.y][world->player->coord.x] = 'P';
}

int	is_accessible(t_world *world, char c, int x, int y)
{
	if (c != '0' && c != 'C' && !(c == 'E' && world->nb_item == 0) && c != 'M')
		return (0);
	else if (c == 'E')
	{
		world->map[y][x] = 'F';
		return (0);
	}
	else if (c == 'M')
	{
		world->map[world->player->coord.y][world->player->coord.x] = 'X';
		return (0);
	}
	return (1);
}

int	is_item(char c)
{
	if (c == 'C')
		return (1);
	return (0);
}
