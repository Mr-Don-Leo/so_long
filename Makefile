NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SRCS = Mandatory/so_long.c Mandatory/rendering.c Mandatory/path_finder.c \
		Mandatory/parsing_utilities.c Mandatory/map_parsing_utilities.c \
		Mandatory/image_check.c Mandatory/extra_utils.c \

OBJS	=	$(SRCS:.c=.o)

LIBFT = libft/libft.a
MLX	 = mlx/libmlx.a


MLXFLAG = -L mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C libft

$(MLX):
	@$(MAKE) -C mlx

$(NAME)	: $(OBJS) $(LIBFT)  $(MLX) 
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAG) -o $@ $(LIBFT) $(MLX)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(MAKE) -C libft clean
	@rm -f $(OBJS)
		
fclean: clean
	@$(MAKE) -C libft fclean
	@$(MAKE) -C mlx clean
	@rm -f $(NAME)

re:	fclean all
 
.PHONY: all clean fclean re bonus