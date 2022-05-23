/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamanfo <kamanfo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:35:26 by kamanfo           #+#    #+#             */
/*   Updated: 2022/01/01 20:04:52 by kamanfo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  INIT_TAB_H
# define INIT_TAB_H

# include "mlx/mlx.h"
# include "get_next_line/get_next_line.h"
# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>

typedef struct lst_map
{
	char			*line;
	size_t			len;
	struct lst_map	*next;
}	t_map;

typedef struct coordonne
{
	int	x;
	int	y;
}	t_Coord;

typedef struct player
{
	t_Coord	coord;
	int		dir;	
}	t_player;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_mlx;

typedef struct image
{
	void	*image;
	int		img_width;
	int		img_height;
}	t_image;

typedef struct animation
{
	t_image	imgset[8];
}	t_anim;

typedef struct world
{
	char		**map;
	t_player	*player;
	t_image		imgset[4];
	t_anim		animset[4];
	t_mlx		*mlx;
	int			nb_item;
	int			count_move;
}	t_world;

t_player	*init_player(int i, int j);
t_map		*creat_lmap_elem(char *line, size_t len);
int			push_last_elem(t_map **lmap, char *line, size_t len);
int			lst_len(t_map *lmap);
int			is_mapset(char c);
int			verif_map(char **map);
char		**initialize_tmap(t_map *lmap);
t_map		*parse_map(int fd);
void		ft_lstclear(t_map **lst);
void		free_map(char **map);
int			checkline(char *line);
int			checkcol(char **col, int j);
int			find_elem(char **map, char c);
void		free_world(t_world *world);
int			check_wall(char **map, int height, int width);
int			check_rules(char **map, int height, int width);
void		player_move(t_world *world, int dir, int y, int x);
int			is_accessible(t_world *world, char c, int x, int y);
int			is_item(char c);
void		init_imageset(t_world *world);
void		init_anim_chest(t_world *world);
void		affiche_elem(t_world world, int i, int j);
void		ft_put_image(t_world world, t_image image, int i, int j);
void		ft_put_animation_image(t_world world, t_image image, int i, int j);
void		init_anim_player(t_world *world);
void		init_anim_enemy(t_world *world);
void		init_images(t_world *world);
void		affiche_map(t_world world);
int			is_exit(t_world world);
void		move(t_world *world, int dir);
int			deal_key(int key, t_world *world);
t_world		init_world(char **map, t_mlx *mlx);
void		animation_slime(t_world world, int size, int i, int j);
void		animation_mino(t_world world, int size, int i, int j);
int			exit_game(t_world *world);
int			refresh(t_world *world);
void		print_error(t_map *lmap);

#endif
