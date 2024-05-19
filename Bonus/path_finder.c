/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 04:10:24 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/17 19:44:46 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	path_finder(t_parsemap **map, char **copy, int x, int y)
{
	if ((*map)->temp_collectibles == -1 && (*map)->temp_exit == -1)
	{
		(*map)->temp_collectibles = (*map)->collectibles;
		(*map)->temp_exit = (*map)->exit;
	}
	if (x < 0 || x > (*map)->collumns || y < 0
		|| y > (*map)->rows || copy[y][x] == WALL)
		return ;
	if (copy[y][x] == EXIT)
	{
		(*map)->temp_exit--;
		(*map)->exit_x = x;
		(*map)->exit_y = y;
		copy[y][x] = WALL;
		return ;
	}
	if (copy[y][x] == COLLE)
		(*map)->temp_collectibles--;
	copy[y][x] = WALL;
	path_finder(map, copy, x + 1, y);
	path_finder(map, copy, x - 1, y);
	path_finder(map, copy, x, y + 1);
	path_finder(map, copy, x, y - 1);
}
