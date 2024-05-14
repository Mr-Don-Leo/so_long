/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:27:14 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/14 19:01:17 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_sprites(t_game *game)
{
	mlx_destroy_image(game->mlx, game->tiles[0]);
	mlx_destroy_image(game->mlx, game->tiles[1]);
	mlx_destroy_image(game->mlx, game->player[0]);
	mlx_destroy_image(game->mlx, game->collectible[0]);
	mlx_destroy_image(game->mlx, game->exit[0]);
}

void	game_exit(t_game *game)
{
	ft_printf("Game Over\n");
	free_maps(game->map->map_main, NULL, game->map);
	free_sprites(game);
	mlx_destroy_window(game->mlx, game->window);
}