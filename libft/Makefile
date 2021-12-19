NAME= libft.a
CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -f
LDFLAGS= -L.
LDLIBS= -lft
SRC= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
ft_memchr.c ft_memcmp.c ft_memcpy.c \
ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putnbr.c\
ft_putendl_fd.c ft_putnbr_fd.c ft_strlcpy.c ft_calloc.c\
ft_putstr_fd.c ft_strchr.c ft_putchar.c ft_nbrlen.c\
ft_strdup.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_split.c ft_strcmp.c\
ft_substr.c ft_strtrim.c ft_tolower.c ft_toupper.c
OBJ = $(SRC:.c=.o)
INC = ./inc/

$(NAME): $(OBJ)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o: %.c
	$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: clean clean
