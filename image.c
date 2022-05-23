/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 16:06:11 by kamanfo           #+#    #+#             */
/*   Updated: 2021/12/28 18:07:22 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_tab.h"

void	init_imageset(t_world *world)
{
	world->imgset[0].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/background.xpm",
			&world->imgset[0].img_width, &world->imgset[0].img_height);
	world->imgset[1].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/walls.xpm",
			&world->imgset[1].img_width, &world->imgset[1].img_height);
	world->imgset[2].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/key.xpm",
			&world->imgset[2].img_width, &world->imgset[2].img_height);
}

void	init_anim_chest(t_world *world)
{
	world->animset[0].imgset[0].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/chestclose.xpm", &world->animset[0].imgset[0].img_width,
			&world->animset[0].imgset[0].img_height);
	world->animset[0].imgset[1].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/chestopen.xpm", &world->animset[0].imgset[1].img_width,
			&world->animset[0].imgset[1].img_height);
}

void	init_anim_player(t_world *world)
{
	world->animset[1].imgset[0].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/slime1.xpm", &world->animset[1].imgset[0].img_width,
			&world->animset[1].imgset[0].img_height);
	world->animset[1].imgset[1].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/slime2.xpm", &world->animset[1].imgset[1].img_width,
			&world->animset[1].imgset[1].img_height);
	world->animset[1].imgset[2].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/slime3.xpm", &world->animset[1].imgset[2].img_width,
			&world->animset[1].imgset[2].img_height);
	world->animset[1].imgset[3].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/slime4.xpm", &world->animset[1].imgset[3].img_width,
			&world->animset[1].imgset[3].img_height);
	world->animset[1].imgset[4].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/slime5.xpm", &world->animset[1].imgset[4].img_width,
			&world->animset[1].imgset[4].img_height);
	world->animset[1].imgset[5].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/slime6.xpm", &world->animset[1].imgset[5].img_width,
			&world->animset[1].imgset[5].img_height);
	world->animset[1].imgset[6].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/slime7.xpm", &world->animset[1].imgset[6].img_width,
			&world->animset[1].imgset[6].img_height);
}

void	init_anim_enemy(t_world *world)
{
	world->animset[2].imgset[0].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/minotaur1.xpm", &world->animset[2].imgset[0].img_width,
			&world->animset[2].imgset[0].img_height);
	world->animset[2].imgset[1].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/minotaur1.xpm", &world->animset[2].imgset[1].img_width,
			&world->animset[2].imgset[1].img_height);
	world->animset[2].imgset[2].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/minotaur3.xpm", &world->animset[2].imgset[2].img_width,
			&world->animset[2].imgset[2].img_height);
	world->animset[2].imgset[3].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/minotaur4.xpm", &world->animset[2].imgset[3].img_width,
			&world->animset[2].imgset[3].img_height);
	world->animset[2].imgset[4].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/minotaur5.xpm", &world->animset[2].imgset[4].img_width,
			&world->animset[2].imgset[4].img_height);
	world->animset[2].imgset[5].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/minotaur6.xpm", &world->animset[2].imgset[5].img_width,
			&world->animset[2].imgset[5].img_height);
	world->animset[2].imgset[6].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/minotaur7.xpm", &world->animset[2].imgset[6].img_width,
			&world->animset[2].imgset[6].img_height);
	world->animset[2].imgset[7].image = mlx_xpm_file_to_image(world->mlx->mlx,
			"./imageset/minotaur8.xpm", &world->animset[2].imgset[7].img_width,
			&world->animset[2].imgset[7].img_height);
}
