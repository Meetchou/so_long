/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:46:05 by kamanfo           #+#    #+#             */
/*   Updated: 2022/01/01 19:02:15 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_tab.h"

void	affiche_elem(t_world world, int i, int j)
{
	if (world.map[i][j] == '0')
		ft_put_image(world, world.imgset[0], i, j);
	else if (world.map[i][j] == '1')
		ft_put_image(world, world.imgset[1], i, j);
	else if (world.map[i][j] == 'C')
		ft_put_image(world, world.imgset[2], i, j);
	else if (world.map[i][j] == 'E')
	{
		ft_put_image(world, world.imgset[0], i, j);
		ft_put_image(world, world.animset[0].imgset[0], i, j);
	}
	else if (world.map[i][j] == 'F')
	{
		ft_put_image(world, world.imgset[0], i, j);
		ft_put_image(world, world.animset[0].imgset[1], i, j);
	}
	else if (world.map[i][j] == 'M')
		animation_mino(world, 8, i, j);
}

int	is_exit(t_world world)
{
	int	i;
	int	j;

	i = 0;
	while (world.map[i])
	{
		j = 0;
		while (is_mapset(world.map[i][j]))
		{
			if (world.map[i][j] == 'F')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	affiche_map(t_world world)
{
	int		i;
	int		j;
	char	*nb_moves;

	i = 0;
	j = 0;
	while (world.map[i])
	{
		j = 0;
		while (is_mapset(world.map[i][j]))
		{
			affiche_elem(world, i, j);
			j++;
		}
		i++;
	}
	nb_moves = ft_itoa(world.count_move);
	mlx_string_put(world.mlx->mlx, world.mlx->win, 100, 100, 0x00FF00FF,
		"Nombres de pas : ");
	mlx_string_put(world.mlx->mlx, world.mlx->win, 200, 100, 0x00FF00FF,
		nb_moves);
	free(nb_moves);
	animation_slime(world, 7, world.player->coord.y, world.player->coord.x);
}

void	move(t_world *world, int dir)
{
	if (dir == 0 && is_accessible(world, world->map[world->player->coord.y - 1]
			[world->player->coord.x], world->player->coord.x,
			world->player->coord.y - 1))
		player_move(world, dir, world->player->coord.y - 1,
			world->player->coord.x);
	else if (dir == 1 && is_accessible(world,
			world->map[world->player->coord.y + 1][world->player->coord.x],
		world->player->coord.x, world->player->coord.y + 1))
		player_move(world, dir, world->player->coord.y + 1,
			world->player->coord.x);
	else if (dir == 2 && is_accessible(world, world->map[world->player->coord.y]
			[world->player->coord.x - 1],
			world->player->coord.x - 1, world->player->coord.y))
		player_move(world, dir, world->player->coord.y,
			world->player->coord.x - 1);
	else if (dir == 3 && is_accessible(world, world->map[world->player->coord.y]
			[world->player->coord.x + 1], world->player->coord.x + 1,
			world->player->coord.y))
		player_move(world, dir, world->player->coord.y,
			world->player->coord.x + 1);
	else
		return ;
}

int	deal_key(int key, t_world *world)
{
	if (is_exit(*world)
		&& world->map[world->player->coord.y][world->player->coord.x] == 'P')
	{
		if (key == 119)
			move(world, 0);
		else if (key == 115)
			move(world, 1);
		else if (key == 97)
			move(world, 2);
		else if (key == 100)
			move(world, 3);
	}
	if (key == 65307)
		free_world(world);
	return (1);
}
