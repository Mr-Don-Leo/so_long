/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:32:57 by mbabayan          #+#    #+#             */
/*   Updated: 2024/04/22 06:43:39 by mbabayan         ###   ########.fr       */
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

int main(int argc, char **argv)
{
	t_game game;
	
	game.map = malloc(sizeof(t_parsing));
	if (argc != 2)
	{
		write(2,"Error: Invalid usage: `./so_long [map].ber`", 44);
		exit(1);	
	}
	map_parse(argv[1], &game);
}
//
// Created by Max on 21/02/2024.
//
