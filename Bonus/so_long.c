/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:32:57 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/17 19:44:39 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	addtext(t_game *game)
{
	char	*moves;

	mlx_put_image_to_window(game->mlx, game->window,
		game->tiles[0], TILE_SIZE, 0);
	mlx_put_image_to_window(game->mlx, game->window, game->tiles[0], 0, 0);
	mlx_string_put(game->mlx, game->window, 10, 10, 0x00FFFFFF, "Moves: ");
	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->window, 90, 10, 0x00FFFFFF, moves);
	free(moves);
	return (0);
}

void	map_parsing(char *path, t_game *game)
{
	init_map(&game->map);
	path_validation(path, &game->map);
	retrieve_map(path, &game->map);
	check_map_size(&game->map);
	check_map_borders(&game->map);
	check_map_elements(&game->map);
	check_element_amount(&game->map);
	path_finder(&game->map, game->map->map_copy, game->map->x, game->map->y);
	check_path_finder_result(&game->map);
	free_maps(NULL, game->map->map_copy, NULL);
}

int	main(int argc, char **argv)
{
	t_game	game;

	game.moves = 0;
	game.direction = 0;
	image_check(set_images());
	game.map = malloc(sizeof(t_parsemap));
	if (argc != 2)
		(write(1, "Error\nInvalid number of arguments\n", 35), exit(EF));
	map_parsing(argv[1], &game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map->collumns * TILE_SIZE,
			game.map->rows * TILE_SIZE, "so_long");
	rendering(&game);
	mlx_hook(game.window, 2, 0, key_handler, &game);
	mlx_hook(game.window, 17, 0, game_exit, &game);
	mlx_loop_hook(game.mlx, addtext, &game);
	mlx_loop(game.mlx);
	return (0);
}
