/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilities.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:28:18 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/11 15:13:32 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdio.h>
void path_validation(char *path, t_parsemap **map)
{
	int fd;

	if (!path)
		(write(1, "Error\nInvalid path\n", 19), free(*map),exit(EF));
	if (ft_strncmp(&path[ft_strlen(path) - 4], ".ber", 4) != 0)
		(write(1, "Error\nInvalid file extension\n", 30), free(*map),exit(EF));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		(write(1, "Error\nFile not found\n", 22), free(*map),exit(EF));
	close (fd);
}

void init_map(t_parsemap **map, t_game *game)
{
	(*map)->player = 0;
	(*map)->collectibles = 0;
	(*map)->exit = 0;
	(*map)->y = 0;
	(*map)->x = 0;
	(*map)->empty_line = -1;
	(*map)->temp_collectibles = -1;
	(*map)->temp_exit = -1;
	game->moves = 0;
	game->controls = 1;	
}

void check_character(char c, t_parsemap **map)
{
	if (c != WALL && c != FLOOR && c != COIN && c != PLAYER && c != EXIT)
	{
		write(1, "Error\nInvalid element in the map\n", 36);
		(free_maps((*map)->map_main, (*map)->map_copy, *map), exit(EF));
	}
}

int check_top_bottom(char *row, char target)
{
	int index;
	int length; 
	
	index = 0;
	length = ft_strlen(row);
	while (index < length)
	{
		if (row[index] != target)
			return (0);
		index++;
	}
	return (1);
}