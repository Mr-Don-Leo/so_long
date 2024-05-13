/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:52:37 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/10 04:31:15 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_maps(char **main_map, char **map_copy, t_parsemap *map)
{
	int index;

	index = -1; 
	if (main_map)
	{
		while (main_map[++index])
			free(main_map[index]);
		free(main_map);
	}
	index = -1;
	if (map_copy)
	{
		while (map_copy[++index])
			free(map_copy[index]);
		free(map_copy);
	}
	if (map)
		free(map);
}

void check_element_amount(t_parsemap **map)
{
	if ((*map)->player != 1 || (*map)->collectibles < 1 || (*map)->exit != 1)
	{
		write(1, "Error\nInvalid amount of elements in the map\n", 45);
		(free_maps((*map)->map_main, (*map)->map_copy, *map), exit(EF));
	}
}

void check_path_finder_result(t_parsemap **map)
{
	if ((*map)->temp_collectibles != 0 || (*map)->temp_exit != 0)
	{
		write(1, "Error\nInvalid map, no path found\n", 34);
		(free_maps((*map)->map_main, (*map)->map_copy, *map), exit(EF));
	}
}