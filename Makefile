SRCS_NAME = so_long free check_map check_map_utils1 check_map_utils2 check_map_utils3 put_image movement movement_utils animation

SRCS = $(SRCS_NAME:=.c)

OBJECTS = $(SRCS:.c=.o)

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -I ./minilibx_opengl_20191021 -I ./libft $<

$(NAME): $(OBJECTS)
	make bonus -C ./libft
	cc $(OBJECTS) -o $(NAME) -g -L ./minilibx_opengl_20191021 -lmlx -L ./libft -lft -framework OpenGL -framework AppKit

clean:
	make clean -C ./libft
	rm -f $(OBJECTS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
