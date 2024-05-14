/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:28:56 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/14 19:48:39 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void frame_update(t_game *game, int upd_x, int upd_y)
{
	game->map->x = upd_x;
	game->map->y = upd_y;
	game->map->map_main[upd_y][upd_x] = PLAYER;
	mlx_put_image_to_window(game->mlx, game->window,
		game->tiles[1], game->map->x * TILE_SIZE, game->map->y * TILE_SIZE);
	mlx_put_image_to_window(game->mlx, game->window,
		game->player[1], upd_x * TILE_SIZE, upd_y * TILE_SIZE);
}

void move_player(t_game *game, int upd_x, int upd_y)
{
	if (game->map->map_main[upd_y][upd_x] == EXIT && game->map->collectibles != 0)
		return ;
	if (game->map->map_main[upd_y][upd_x] == WALL)
		return ;
	game->moves = game->moves + 1;
	ft_printf("Moves: %d\n", game->moves);
	if (game->map->map_main[upd_y][upd_x] == COLLE)
		game->map->collectibles--;
	mlx_put_image_to_window(game->mlx, game->window, game->tiles[1],
		game->map->x * TILE_SIZE, game->map->y * TILE_SIZE);
	if (game->map->map_main[upd_y][upd_x] == EXIT && game->map->collectibles == 0)
	{
		ft_printf("You Win!\n");
		return(game_exit(game));
	}
	frame_update(game, upd_x, upd_y);	
}

void change_direction(t_game *game, int direction)
{
	if (game->direction == direction)
		return ;
	if (direction == 0)
		game->player[1] = mlx_xpm_file_to_image(game->mlx,
			"./Mandatory/textures/left.xpm", &game->tile, &game->tile);
	if (direction == 1)
		game->player[1] = mlx_xpm_file_to_image(game->mlx,
			"./Mandatory/textures/right.xpm", &game->tile, &game->tile);
	game->direction = direction;
}

int key_handler(int keycode, t_game *game)
{
	if (keycode == ESC)
		game_exit(game);
	if (keycode == UP || keycode == W)
		move_player(game, game->map->x, game->map->y-1);
	if (keycode == DOWN || keycode == S)
		move_player(game, game->map->x, game->map->y+1);
	if (keycode == LEFT || keycode == A)
	{
		change_direction(game, 0);
		move_player(game, game->map->x-1, game->map->y);
	}
	if (keycode == RIGHT || keycode == D)
	{
		change_direction(game, 1);
		move_player(game, game->map->x+1, game->map->y);
	}
	return (0);
}
