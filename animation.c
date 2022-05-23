/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:02:05 by kamanfo           #+#    #+#             */
/*   Updated: 2021/12/28 16:20:01 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_tab.h"

void	ft_put_animation_image(t_world world, t_image image, int i, int j)
{
	mlx_put_image_to_window(world.mlx->mlx, world.mlx->win,
		image.image, j, i);
}

void	animation_slime(t_world world, int size, int i, int j)
{
	static int	k = 0;

	if (k == size)
		k = 0;
	usleep(20000);
	ft_put_animation_image(world, world.animset[1].imgset[k],
		i * world.imgset[0].img_width, (world.imgset[0].img_height * j));
	k++;
}

void	animation_mino(t_world world, int size, int i, int j)
{
	static int	l = 0;

	usleep(20000);
	if (l == size)
		l = 0;
	ft_put_animation_image(world, world.animset[2].imgset[l],
		i * world.imgset[0].img_width, (world.imgset[0].img_height * j));
	l++;
}
