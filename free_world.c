/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:11:20 by kamanfo           #+#    #+#             */
/*   Updated: 2022/01/01 19:06:29 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_tab.h"

void	ft_lstdelone(t_map *lst)
{
	if (!lst)
		return ;
	free(lst->line);
	free(lst);
}

void	ft_lstclear(t_map **lst)
{
	t_map	*t;
	t_map	*tmp;

	t = *lst;
	while (t)
	{
		tmp = t->next;
		ft_lstdelone(t);
		t = tmp;
	}
	*lst = NULL;
}

void	free_animset(t_world *world, int anim, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_destroy_image(world->mlx->mlx,
			world->animset[anim].imgset[i].image);
		i++;
	}
}

void	free_animset_enemy(t_world *world, int anim, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_destroy_image(world->mlx->mlx,
			world->animset[anim].imgset[i].image);
		i++;
	}
}

void	free_world(t_world *world)
{
	int	i;

	i = 0;
	free_map(world->map);
	free(world->player);
	while (i < 3)
	{
		mlx_destroy_image(world->mlx->mlx, world->imgset[i].image);
		i++;
	}
	free_animset(world, 0, 2);
	free_animset(world, 1, 7);
	free_animset_enemy(world, 2, 8);
	mlx_destroy_window(world->mlx->mlx, world->mlx->win);
	mlx_destroy_display(world->mlx->mlx);
	mlx_loop_end(world->mlx->mlx);
	free(world->mlx->mlx);
	exit(1);
}
