/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:25:48 by mbabayan          #+#    #+#             */
/*   Updated: 2024/05/23 04:58:51 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	image_check(void)
{
	static char		*list[6] = {
		"./Mandatory/Textures/wall.xpm",
		"./Mandatory/Textures/floor.xpm",
		"./Mandatory/Textures/collectible.xpm",
		"./Mandatory/Textures/right.xpm",
		"./Mandatory/Textures/left.xpm",
		"./Mandatory/Textures/exit.xpm"
	};
	int				index;
	int				fd;
	char			buffer[1];
	size_t			ret;

	index = 1;
	while (++index < 6)
	{
		fd = open(list[index], O_RDONLY);
		if (fd == -1)
			(write(1, "Error\nImage not found\n", 23), exit(EF));
		ret = read(fd, buffer, 1);
		if (ret == 0)
			(write(1, "Error\nEmpty Image\n", 19),
				close(fd), exit(EF));
		close (fd);
	}
}
