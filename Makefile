NAME = so_long
BONUS = so_long_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
PURPLE=\033[0;35m
ORANGE=\033[38;5;208m
NC=\033[0m

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
	@echo "$(YELLOW)Compiling libft...$(NC)"
	@$(MAKE) -C libft
	@echo "$(GREEN)Finished compiling libft.$(NC)"
	@echo

$(MLX):
	@echo "$(YELLOW)Compiling mlx...$(NC)"
	@$(MAKE) -C mlx
	@echo "$(GREEN)Finished compiling mlx.$(NC)"
	@echo

$(PRINTF):
	@echo "$(YELLOW)Compiling printf...$(NC)"
	@$(MAKE) -C printf
	@echo "$(GREEN)Finished compiling printf.$(NC)"
	@echo

$(NAME): $(OBJS) $(LIBFT) $(MLX) $(PRINTF)
	@echo "$(YELLOW)Compiling $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAG) -o $@ $(LIBFT) $(MLX) $(PRINTF)
	@echo "$(GREEN)Finished compiling $(NAME).$(NC)"
	@echo

%.o: %.c
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(GREEN)Finished compiling $<.$(NC)"
	@echo

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(LIBFT) $(MLX) $(PRINTF)
	@echo "$(YELLOW)Compiling $(BONUS)...$(NC)"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(MLXFLAG) -o $@ $(LIBFT) $(MLX) $(PRINTF)
	@echo "$(GREEN)Finished compiling $(BONUS).$(NC)"
	@echo

clean:
	@echo "$(ORANGE)Cleaning up object files...$(NC)"
	@$(MAKE) -C libft clean
	@rm -f $(OBJS)
	@rm -f $(BONUS_OBJS)
	@echo "$(ORANGE)Cleanup complete.$(NC)"
	@echo

fclean: clean
	@echo "$(RED)Performing full clean...$(NC)"
	@$(MAKE) -C libft fclean
	@$(MAKE) -C mlx clean
	@$(MAKE) -C printf fclean
	@rm -f $(NAME)
	@rm -f $(BONUS)
	@echo "$(RED)Full clean complete.$(NC)"
	@echo

re: fclean all

norm:
	@echo "$(PURPLE)Checking norminette...$(NC)"
	@echo
	@python3 -m norminette ./PRINTF ./LIBFT ./Mandatory ./Bonus

.PHONY: all clean fclean re bonus
