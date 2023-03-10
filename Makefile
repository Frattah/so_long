SRCS	=

OBJS	=

NAME	=	fdf.a

all:	$(NAME)

%.o: %.c
	cc -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJS)
	cc $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)