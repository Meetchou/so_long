#include <mlx.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

typedef struct coordonne
{
	int i;
	int y;
} Coord;

typedef struct lst_map
{
	char *line;
	size_t len;
	struct lst_map *next;
} L_map;

typedef struct world
{
	char **map;
	Coord *player_pos;
	Coord *exit_pos;
	int nb_item;
	struct lst_map *next;
} World;


L_map	*creat_lmap_elem(char *line, size_t len)
{
	L_map	*tmp;
	tmp = (L_map *)malloc(sizeof(L_map));
	if (!tmp)
		return (NULL);
	tmp->line = line;
	tmp->len = len;
	tmp->next = NULL;
	return (tmp);
}

int	push_last_elem(L_map **lmap, char *line, size_t len)
{	
	L_map	*tmp;
	L_map	*elem;
	
	tmp = NULL;
	if (!lmap)
		return (0);
	elem = creat_lmap_elem(line, len);
	if(!(*lmap))
		*lmap = elem;
	else
	{
		tmp = *lmap;
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	return (1);
}

void affiche_lmap(L_map *lmap)
{
	L_map *tmp;

	tmp = lmap;
	while (tmp)
	{
		printf("line %s, len %zu\n", tmp->line, tmp->len);
		tmp = tmp->next;
	}
}

L_map *parse_map(int fd)
{
	L_map *lmap;
	size_t len;
	int i;
	char *line;

	i = 0;
	len = 0;
	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	lmap = creat_lmap_elem(line, len);
	while ((line = get_next_line(fd)))
	{
		if (!line)
			return (NULL);
		if (ft_strlen(line) != len)
			return (free(line), NULL); //ne pas oublier de free la list;
		push_last_elem(&lmap, line, len);
		if (!lmap)
			return (NULL);
	}
	return (lmap);
}

int	lst_len(L_map *lmap)
{
	L_map	*tmp;
	int		i;
	if (!lmap)
		return 0;
	tmp = lmap;
	i = 0;
	while(tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int is_mapset(char c)
{
	if (c == '0' || c == '1' || c == 'C' 
			|| c == 'E' || c == 'P')
		return (1);
	return (0);
}

int verif_map(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j])
		{
			printf("%c \n", map[i][j]);
			if (!is_mapset(map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char **initialize_tmap(L_map *lmap)
{
	int i;
	int len;
	char **tab;

	len = lst_len(lmap);
	tab = (char **)malloc(len + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab[i] = ft_strdup(lmap->line);
		if (!tab[i])
			return (NULL); //ne pas oublier de tous free;
		i++;
		lmap = lmap->next;
	}
	tab[i] = NULL;
	if (!verif_map(tab))
		return (NULL);
	return (tab);
	
}

int	main(int ac, char *av[])
{
	int		fd;
	L_map	*lmap;
	char	**map;
	int		i;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	int		img_width;
	int		img_height;
	void	*imgset[5];
	int j;

	if (ac < 2)
		return (-1);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (-1);
	lmap = parse_map(fd);
	if (!lmap)
		return (-1);
	map = initialize_tmap(lmap);
	if (!map)
	{
		printf("NOON");
		return (0);
	}

	//img_height = 480/6;
	//img_width = 640/34;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 640, 480, "Hello world!");
	img = mlx_xpm_file_to_image(mlx, "./tile_0037.xpm", &img_width, &img_height);
	if (!img)
		printf("laaaaa");
	img2 = mlx_xpm_file_to_image(mlx, "./tile_0016.xpm", &img_width, &img_height);
	if (!img2)
		printf("laaaaa2");
	img3 = mlx_xpm_file_to_image(mlx, "./tile_0024.xpm", &img_width, &img_height);
	if (!img3)
		printf("laaaaa3");
	img4 = mlx_xpm_file_to_image(mlx, "./tile_0017.xpm", &img_width, &img_height);
	if (!img4)
		printf("laaaaa4");
	img5 = mlx_xpm_file_to_image(mlx, "./tile_0067.xpm", &img_width, &img_height);
	if (!img5)
		printf("laaaaa5");
	i = 0;
	
	while (map[i])
	{
		
		j = 0;
		while (is_mapset(map[i][j]))
		{
			printf("i = %c\n", map[i][j]);
			if (map[i][j] == '0')
				mlx_put_image_to_window(mlx, mlx_win, img, i * img_height, j * img_width);
			else if (map[i][j] == '1')s
				mlx_put_image_to_window(mlx, mlx_win, img5, i * img_height, j * img_width); 
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, img2, i * img_height, j * img_width);
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, img3, i * img_height, j * img_width);
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, img4, i * img_height, j * img_width);
			else
				return (0);
			j++;
		}
		i++;
	}
	mlx_loop(mlx);
}
