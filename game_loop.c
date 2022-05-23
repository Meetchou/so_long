/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:18:44 by kamanfo           #+#    #+#             */
/*   Updated: 2022/01/01 18:55:53 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_tab.h"

int	exit_game(t_world *world)
{
	free_world(world);
	return (1);
}

int	refresh(t_world *world)
{
	usleep(20000);
	affiche_map(*world);
	world->player->dir = -1;
	if (!is_exit(*world))
		mlx_string_put(world->mlx->mlx, world->mlx->win,
			250, 300, 0x00FF00FF, "Victoire !!");
	else if (world->map[world->player->coord.y][world->player->coord.x] == 'X')
		mlx_string_put(world->mlx->mlx, world->mlx->win,
			250, 300, 0x00FF00FF, "PERDU !!");
	return (1);
}
