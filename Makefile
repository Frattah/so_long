SRCS	= main.c	gnl/get_next_line.c gnl/get_next_line_utils.c	utils.c map_utils.c putting_function.c	commands.c

OBJS	= $(SRCS:.c=.o)

NAME	=	so_long

CC		=	gcc

CFLAG	=	-Wall -Wextra -Werror -o3

all:	$(NAME)

%.o: %.c
	$(CC) $(CFLAG) -D BUFFER_SIZE=42 -Imlx -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAG) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf $(OBJS)

re:	fclean all

.PHONY: re fclean all clean