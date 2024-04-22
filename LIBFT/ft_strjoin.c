/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:56:42 by mbabayan          #+#    #+#             */
/*   Updated: 2024/03/28 15:05:38 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strjoin allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 */
char	*ft_strjoin(char *conserve, char *buffer)
{
	char	*new_string;
	int		index;
	int		index2;

	index = 0;
	index2 = 0;
	if (!conserve && !buffer)
		return (NULL);
	new_string = malloc(sizeof(char) * (ft_strlen(conserve)
				+ ft_strlen(buffer) + 1));
	if (!new_string)
		return (NULL);
	while (conserve && conserve[index] != '\0')
	{
		new_string[index] = conserve[index];
		index++;
	}
	while (buffer[index2] != '\0')
		new_string[index++] = buffer[index2++];
	new_string[index++] = '\0';
	if (conserve)
		free(conserve);
	return (new_string);
}