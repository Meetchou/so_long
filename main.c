/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:39:07 by kamanfo           #+#    #+#             */
/*   Updated: 2022/03/06 20:33:40 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_tab.h"

void	print_error(t_map *lmap)
{
	ft_lstclear(&lmap);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	print_mlx_error(char **map)
{
	free_map(map);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	main(int ac, char *av[])
{
	int		fd;
	t_mlx	mlx;
	char	**map;
	t_world	world;
	t_map	*lmap;

	if (ac != 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	lmap = parse_map(fd);
	map = initialize_tmap(lmap);
	if (!check_rules(map, lst_len(lmap), lmap->len))
		print_error(lmap);
	ft_lstclear(&lmap);
	mlx.mlx = mlx_init();
	if (!(mlx.mlx))
		print_mlx_error(map);
	mlx.win = mlx_new_window(mlx.mlx, 2500, 1000, "Hello world!");
	world = init_world(map, &mlx);
	mlx_hook(world.mlx->win, 2, 1L << 0, deal_key, &world);
	mlx_hook(world.mlx->win, 17, 0L, exit_game, &world);
	mlx_loop_hook(world.mlx->mlx, refresh, &world);
	mlx_loop(world.mlx->mlx);
	return (1);
}
