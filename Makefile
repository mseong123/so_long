SRCS_NAME = so_long free event_handlers 

SRCS = $(SRCS_NAME:=.c)

OBJECTS = $(SRCS:.c=.o)

NAME = so_long

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -I ./minilibx_opengl_20191021 $<

$(NAME): $(OBJECTS)
	cc $(OBJECTS) -o $(NAME) -g -L ./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
