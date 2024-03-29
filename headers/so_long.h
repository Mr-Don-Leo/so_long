/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:11:53 by mbabayan          #+#    #+#             */
/*   Updated: 2024/03/03 15:12:21 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "../MLX/mlx.h"
# include "../LIBFT/libft.h"
# include "../GNL/get_next_line.h"
# include "../PRINTF/ft_printf.h"
# include <fcntl.h>


/*
 * Define Images here
 * # define "image/location"
 */

/*
 * Define a struct, for the game
 */
typedef struct s_game
{
	int width;
	int height;
	char **map;
	int collectibles;

};


#endif //SO_LONG_H
