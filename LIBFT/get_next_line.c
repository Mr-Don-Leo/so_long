/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:58:39 by mbabayan          #+#    #+#             */
/*   Updated: 2024/03/28 15:14:12 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(char *conserve)
{
	int		index;
	char	*line;

	index = 0;
	if (!conserve[index])
		return (NULL);
	while (conserve[index] != '\0' && conserve[index] != '\n')
		index++;
	line = malloc(sizeof(char) * (index + 1 + (conserve[index] == '\n')));
	if (!line)
		return (NULL);
	index = 0;
	while (conserve[index] != '\0' && conserve[index] != '\n')
	{
		line[index] = conserve[index];
		index++;
	}
	if (conserve[index] == '\n')
	{
		line[index] = conserve[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}
/*
 * function that returns the rest of the string
 */
static char	*ft_save(char *conserve)
{
	int		index;
	int		index2;
	char	*buffer;

	index = 0;
	index2 = 0;
	while (conserve[index] != '\0' && conserve[index] != '\n')
		index++;
	if (!conserve[index])
	{
		free(conserve);
		return (NULL);
	}
	buffer = malloc(sizeof(char) * ((ft_strlen(conserve) - index) + 1));
	if (!buffer)
		return (NULL);
	index++;
	while (conserve[index] != '\0')
		buffer[index2++] = conserve[index++];
	buffer[index2] = '\0';
	free(conserve);
	return (buffer);
}

static char	*ft_readfile(char *conserve, int fd)
{
	int		rd;
	char	*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (ft_strchr(conserve, '\n') == 0 && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			if (conserve != NULL)
				free(conserve);
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		conserve = ft_strjoin(conserve, buffer);
	}
	free(buffer);
	return (conserve);
}

/*
 * function read file line by line, it first checks if fd
 * is valid, if the buffer size is valid and if the buffer
 * size is not bigger than the max int value and then it
 * calls the ft_readfile function to read the file and

 */
char	*get_next_line(int fd)
{
	char		*print;
	static char	*conserve;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	conserve = ft_readfile(conserve, fd);
	if (!conserve)
		return (NULL);
	print = ft_get_line(conserve);
	conserve = ft_save(conserve);
	return (print);
}
