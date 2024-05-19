/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utilities.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:09:19 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/17 19:44:55 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	count_lines(char *path, t_parsemap **map)
{
	int	fd;
	int	index;

	index = 0;
	fd = open(path, O_RDONLY);
	(*map)->line = get_next_line(fd);
	if (!(*map)->line)
		(write(1, "Error\nEmpty file\n", 17), close(fd), free(*map), exit(EF));
	while ((*map)->line)
	{
		index++;
		if ((*map)->line[0] == '\n')
			(*map)->empty_line = 1;
		if ((*map)->line[0] != '\n' && (*map)->empty_line == 1)
		{
			write(2, "Error:\nEmpty line found in the map.\n", 29);
			(free((*map)->line), (void)close(fd), free (*map), exit(EF));
		}
		else if ((*map)->line[0] != '\n')
			(*map)->rows = index;
		free ((*map)->line);
		(*map)->line = get_next_line(fd);
	}
	free ((*map)->line);
	close (fd);
}

void	check_map_size(t_parsemap **map)
{
	int	index;
	int	temporary;

	index = 1;
	(*map)->collumns = ft_strlen((*map)->map_main[0]);
	if ((*map)->collumns < 3 || (*map)->rows < 3)
	{
		write(1, "Error\nMap is too small\n", 23);
		(free_maps((*map)->map_main, (*map)->map_copy, *map), exit(EF));
	}
	if ((*map)->collumns > 23 || (*map)->rows > 11)
	{
		write(1, "Error\nMap is too big\n", 21);
		(free_maps((*map)->map_main, (*map)->map_copy, *map), exit(EF));
	}
	while ((*map)->map_main[index])
	{
		temporary = ft_strlen((*map)->map_main[index++]);
		if (temporary != (*map)->collumns)
		{
			write(1, "Error\nMap is not rectangular\n", 29);
			(free_maps((*map)->map_main, (*map)->map_copy, *map), exit(EF));
		}
	}
}

void	check_map_borders(t_parsemap **map)
{
	int	index;

	index = 0;
	if (check_top_bottom((*map)->map_main[0], WALL) == 0
		|| check_top_bottom((*map)->map_main[(*map)->rows - 1], WALL) == 0)
	{
		write(1, "Error\nMap is not surrounded by walls\n", 37);
		(free_maps((*map)->map_main, (*map)->map_copy, *map), exit(EF));
	}
	while (index < (*map)->rows)
	{
		if ((*map)->map_main[index][0] != WALL
			|| (*map)->map_main[index][(*map)->collumns - 1] != WALL)
		{
			write(1, "Error\nMap is not surrounded by walls\n", 37);
			(free_maps((*map)->map_main, (*map)->map_copy, *map), exit(EF));
		}
		index++;
	}
}

void	check_map_elements(t_parsemap **map)
{
	int	index;
	int	index2;

	index = 0;
	index2 = 0;
	while ((*map)->map_main[index])
	{
		while ((*map)->map_main[index][index2])
		{
			check_character((*map)->map_main[index][index2], map);
			if ((*map)->map_main[index][index2] == PLAYER)
			{
				(*map)->player++;
				(*map)->x = index2;
				(*map)->y = index;
			}
			if ((*map)->map_main[index][index2] == COLLE)
				(*map)->collectibles++;
			if ((*map)->map_main[index][index2] == EXIT)
				(*map)->exit++;
			index2++;
		}
		index2 = 0;
		index++;
	}
}

void	retrieve_map(char *path, t_parsemap **map)
{
	int	index;
	int	fd;

	index = 0;
	fd = open(path, O_RDONLY);
	count_lines(path, map);
	(*map)->map_main = (char **)malloc(sizeof(char *) * ((*map)->rows + 1));
	(*map)->map_copy = malloc(sizeof(char *) * ((*map)->rows + 1));
	if (!(*map)->map_copy || !(*map)->map_main)
	{
		write(1, "Error\nMalloc failed\n", 20);
		free_maps((*map)->map_main, (*map)->map_copy, *map);
		exit(EF);
	}
	while (index < (*map)->rows)
	{
		(*map)->map_main[index] = ft_strtrim(get_next_line(fd), "\n");
		(*map)->map_copy[index] = ft_strdup((*map)->map_main[index]);
		index++;
	}
	(*map)->map_main[index] = NULL;
	(*map)->map_copy[index] = NULL;
	close(fd);
}
