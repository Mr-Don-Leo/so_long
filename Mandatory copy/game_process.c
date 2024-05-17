/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:28:56 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/17 15:28:31 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	frame_update(t_game *game, int upd_x, int upd_y, int dir)
{
	game->map->x = upd_x;
	game->map->y = upd_y;
	game->map->map_main[upd_y][upd_x] = PLAYER;
	mlx_put_image_to_window(game->mlx, game->window,
		game->tiles[1], game->map->x * TILE_SIZE, game->map->y * TILE_SIZE);
	if (dir == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->player[0], upd_x * TILE_SIZE, upd_y * TILE_SIZE);
		game->direction = 0;
	}
	else
	{
		mlx_put_image_to_window(game->mlx, game->window,
			game->player[1], upd_x * TILE_SIZE, upd_y * TILE_SIZE);
		game->direction = 1;
	}
}

void	move_player(t_game *game, int upd_x, int upd_y, int dir)
{
	if (game->map->map_main[upd_y][upd_x] == EXIT
		&& game->map->collectibles != 0)
		return ;
	if (game->map->map_main[upd_y][upd_x] == WALL)
		return ;
	game->moves = game->moves + 1;
	ft_printf("Moves: %d\n", game->moves);
	if (game->map->map_main[upd_y][upd_x] == COLLE)
		game->map->collectibles--;
	mlx_put_image_to_window(game->mlx, game->window, game->tiles[1],
		game->map->x * TILE_SIZE, game->map->y * TILE_SIZE);
	if (game->map->map_main[upd_y][upd_x] == EXIT
		&& game->map->collectibles == 0)
	{
		ft_printf("You Win!\n");
		game_exit(game);
	}
	frame_update(game, upd_x, upd_y, dir);
}

int	key_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		game_exit(game);
	if (keycode == UP || keycode == W)
		move_player(game, game->map->x, game->map->y - 1, game->direction);
	if (keycode == DOWN || keycode == S)
		move_player(game, game->map->x, game->map->y + 1, game->direction);
	if (keycode == LEFT || keycode == A)
		move_player(game, game->map->x - 1, game->map->y, 1);
	if (keycode == RIGHT || keycode == D)
		move_player(game, game->map->x + 1, game->map->y, 0);
	return (0);
}
