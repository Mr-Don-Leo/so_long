/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:11:53 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/13 17:34:16 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
	Libraries
*/

# include "../MLX/mlx.h"
# include "../LIBFT/libft.h"
# include <stdio.h>
# include <fcntl.h>

/*
	Defines
*/

# define TILE_SIZE			16
# define WALL				'1'
# define FLOOR				'0'
# define COLLE				'C'
# define PLAYER				'P'
# define EXIT				'E'
# define EF					EXIT_FAILURE
# define ES					EXIT_SUCCESS

/*
	Structs
*/

typedef struct s_parsemap
{
	int		fd;
	int		rows;
	int		collumns;
	int		empty_line;
	char	*line;
	char	**map_main;
	char	**map_copy;
	int		collectibles;
	int		temp_collectibles;
	int		exit;
	int		temp_exit;
	int		player;
	int		x;
	int		exit_x;
	int		y;
	int		exit_y;
}	t_parsemap;

typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*tiles[2];
	void		*collectible[0];
	void		*player[2];
	int			exitflag;
	void		*exit[0];
	int			tile;
	int			moves;
	int			controls;
	int			exitcollected;
	t_parsemap	*map;
}	t_game;

/*
	Func Prototypes
*/
void	init_map(t_parsemap **map, t_game *game);
void 	image_check(char **set);
char 	**set_images();
void	path_validation(char *path, t_parsemap **map);
void	retrieve_map(char *path, t_parsemap **map);
void	free_maps(char **main_map, char **map_copy, t_parsemap *map);
void	check_map_size(t_parsemap **map);
void	check_map_borders(t_parsemap **map);
int		check_top_bottom(char *row, char target);
void	check_map_elements(t_parsemap **map);
void	check_character(char c, t_parsemap **map);
void	check_element_amount(t_parsemap **map);
void	path_finder(t_parsemap **map, char **copy, int x, int y);
void	check_path_finder_result(t_parsemap **map);
void	rendering(t_game *game);

#endif //SO_LONG_H
