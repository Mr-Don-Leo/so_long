/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:37:59 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/15 16:17:13 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_elements(t_game *game)
{
	game->tile = TILE_SIZE;
	game->tiles[0] = mlx_xpm_file_to_image(game->mlx,
			"./Mandatory/textures/wall.xpm", &game->tile, &game->tile);
	game->tiles[1] = mlx_xpm_file_to_image(game->mlx,
			"./Mandatory/textures/floor.xpm", &game->tile, &game->tile);
	game->collectible[0] = mlx_xpm_file_to_image(game->mlx,
			"./Mandatory/textures/collectible.xpm", &game->tile, &game->tile);
	game->player[0] = mlx_xpm_file_to_image(game->mlx,
			"./Mandatory/textures/right.xpm", &game->tile, &game->tile);
	game->player[1] = mlx_xpm_file_to_image(game->mlx,
			"./Mandatory/textures/left.xpm", &game->tile, &game->tile);
	game->exit[0] = mlx_xpm_file_to_image(game->mlx,
			"./Mandatory/textures/exit.xpm", &game->tile, &game->tile);
}

void render_edges(t_game *game)
{
	int index;
	int index2;

	index = -1;
	index2 = -1;
	while (game->map->map_main[++index])
	{
		while (game->map->map_main[index][++index2])
		{
			if ((index == 0 || index == game->map->rows - 1)
				|| (index2 == 0 || index2 == game->map->collumns - 1))
				mlx_put_image_to_window(game->mlx, game->window,
					game->tiles[0], index2 * TILE_SIZE, index * TILE_SIZE);
		}
		index2 = -1;
	}
}

void render_map(t_game *game)
{
	int index;
	int index2;

	index = 0;
	index2 = 0;
	while (index < game->map->rows - 1)
	{
		while (index2 < game->map->collumns - 1)
		{
			if (game->map->map_main[index][index2] == WALL)
				mlx_put_image_to_window(game->mlx, game->window, game->tiles[0],
					index2 * TILE_SIZE, index * TILE_SIZE);
			if (game->map->map_main[index][index2] == FLOOR)
				mlx_put_image_to_window(game->mlx, game->window, game->tiles[1],
					index2 * TILE_SIZE, index * TILE_SIZE);
			index2++;
		}
		index2 = 0;
		index++;
	}
}

void render_elements(t_game *game)
{
	int index;
	int index2;

	index = 0;
	index2 = 0;
	while (index < game->map->rows - 1)
	{
		while (index2 < game->map->collumns - 1)
		{
			if (game->map->map_main[index][index2] == PLAYER)
				mlx_put_image_to_window(game->mlx, game->window, game->player[0],
					index2 * TILE_SIZE, index * TILE_SIZE);
			if (game->map->map_main[index][index2] == COLLE)
				mlx_put_image_to_window(game->mlx, game->window, game->collectible[0],
					index2 * TILE_SIZE, index * TILE_SIZE);
			if (game->map->map_main[index][index2] == EXIT)
				mlx_put_image_to_window(game->mlx, game->window, game->exit[0],
					index2 * TILE_SIZE, index * TILE_SIZE);
			index2++;
		}
		index2 = 0;
		index++;
	}
}

void  rendering(t_game *game)
{
	init_elements(game);
	render_edges(game);
	render_map(game);
	render_elements(game);
}