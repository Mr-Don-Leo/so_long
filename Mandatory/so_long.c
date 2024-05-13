/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:32:57 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/13 15:39:16 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
 key codes:
 53: esc;
 123: left arrow;
 124: right arrow;
 125: down arrow;
 126: up arrow;
 13: w;
 0: a;
 1: s;
 2: d;
*/

void map_parsing(char *path, t_game *game)
{
	init_map(&game->map, game);
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
int main(int argc, char **argv)
{
	t_game game;

	image_check(set_images());
	game.map = malloc(sizeof(t_parsemap));
	if (argc != 2)
		(write(1, "Error\nInvalid number of arguments\n", 35), exit(EF));
	map_parsing(argv[1], &game);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.map->collumns * 16,
		game.map->rows * 16, "so_long");
	rendering(&game);
	return (0);
}
