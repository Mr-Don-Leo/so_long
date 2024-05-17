/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:25:48 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/17 15:26:02 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**set_images(void)
{
	static char	*list[6] = {
		"./Mandatory/Textures/wall.xpm",
		"./Mandatory/Textures/floor.xpm",
		"./Mandatory/Textures/collectible.xpm",
		"./Mandatory/Textures/right.xpm",
		"./Mandatory/Textures/left.xpm",
		"./Mandatory/Textures/exit.xpm"
	};

	return (list);
}

void	image_check(char **set)
{
	int	index;
	int	fd;

	index = 0;
	while (index < 5)
	{
		fd = open(set[index], O_RDONLY);
		if (fd == -1)
			(write(1, "Error\nImage not found\n", 23), exit(EF));
		close (fd);
		index++;
	}
}
