NAME = so_long

LIBFT = ./libft/libft.a

MLX = ./mlx/libmlx.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

SRC = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
		init_tab.c init_tab_utils.c check_map.c free_world.c game_utils.c\
		game.c init_world.c animation.c game_loop.c image.c main.c

OBJ = $(SRC:.c=.o)

SRCC = checker.c $(SRC)

OBJC = $(SRCC:.c=.o)

FL_MLX	=	 -ldl -lmlx -Lmlx -lm -lXext -lX11 -Imlx mlx/libmlx.a

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C ./libft
	$(MAKE) -C ./mlx
	$(CC) $(CFLAGS) $(FL_MLX) $(OBJ) -o $(NAME)  $(LIBFT) $(MLX) -g

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@
clean:
	$(MAKE) clean -C ./libft
	$(MAKE) clean -C ./mlx
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus
