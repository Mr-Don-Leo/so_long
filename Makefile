NAME = so_long
BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SRCS = Mandatory/so_long.c Mandatory/rendering.c Mandatory/path_finder.c \
		Mandatory/parsing_utilities.c Mandatory/map_parsing_utilities.c \
		Mandatory/image_check.c Mandatory/extra_utils.c Mandatory/game_process.c Mandatory/game_over.c 
		
BONUS_SRCS = Bonus/so_long.c Bonus/rendering.c Bonus/path_finder.c \
		Bonus/parsing_utilities.c Bonus/map_parsing_utilities.c \
		Bonus/image_check.c Bonus/extra_utils.c Bonus/game_process.c Bonus/game_over.c 

OBJS	=	$(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = libft/libft.a
MLX	 = mlx/libmlx.a
PRINTF = PRINTF/libftprintf.a

MLXFLAG = -L mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(LIBFT):
	@echo "Compiling libft..."
	@$(MAKE) -C libft
	@echo "Finished compiling libft."
	@echo

$(MLX):
	@echo "Compiling mlx..."
	@$(MAKE) -C mlx
	@echo "Finished compiling mlx."
	@echo

$(PRINTF):
	@echo "Compiling printf..."
	@$(MAKE) -C printf
	@echo "Finished compiling printf."
	@echo

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(PRINTF)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAG) -o $@ $(LIBFT) $(MLX) $(PRINTF)
	@echo "Finished compiling $(NAME)."
	@echo

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Finished compiling $<."
	@echo

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(LIBFT) $(MLX) $(PRINTF)
	@echo "Compiling $(BONUS)..."
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLXFLAG) -o $@ $(LIBFT) $(MLX) $(PRINTF)
	@echo "Finished compiling $(BONUS)."
	@echo

clean:
	@echo "Cleaning up object files..."
	@$(MAKE) -C libft clean
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@echo "Cleanup complete."
	@echo

fclean: clean
	@echo "Performing full clean..."
	@$(MAKE) -C libft fclean
	@$(MAKE) -C mlx clean
	@$(MAKE) -C printf fclean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@echo "Full clean complete."
	@echo

re: fclean all

.PHONY: all clean fclean re bonus
