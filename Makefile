NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SRCS = Mandatory/so_long.c Mandatory/rendering.c Mandatory/path_finder.c \
		Mandatory/parsing_utilities.c Mandatory/map_parsing_utilities.c \
		Mandatory/image_check.c Mandatory/extra_utils.c Mandatory/game_process.c Mandatory/game_over.c \

OBJS	=	$(SRCS:.c=.o)

LIBFT = libft/libft.a
MLX	 = mlx/libmlx.a
PRINTF = PRINTF/libftprintf.a


MLXFLAG = -L mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C libft

$(MLX):
	@$(MAKE) -C mlx

$(PRINTF):
	@$(MAKE) -C printf

$(NAME)	: $(OBJS) $(LIBFT)  $(MLX) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAG) -o $@ $(LIBFT) $(MLX) $(PRINTF)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(MAKE) -C libft clean
	@rm -f $(OBJS)
		
fclean: clean
	@$(MAKE) -C libft fclean
	@$(MAKE) -C mlx clean
	@$(MAKE) -C printf fclean
	@rm -f $(NAME)

re:	fclean all
 
.PHONY: all clean fclean re bonus