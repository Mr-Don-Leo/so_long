/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbabayan <mbabayan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:59:02 by mbabayan          #+#    #+#             */
/*   Updated: 2023/12/18 14:21:20 by mbabayan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
 * function that returns the length of string
 */
int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
 * function that concatenates two strings
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

/*
 * function that returns the first occurence of c in s
 */
char	*ft_strchr(char *concerve, int c)
{
	int	i;

	i = 0;
	if (!concerve)
		return (0);
	if ((char)c == '\0')
		return (&concerve[ft_strlen(concerve)]);
	while (concerve[i])
	{
		if (concerve[i] == (char)c)
			return (&concerve[i]);
		i++;
	}
	return (0);
}

/*
 * function that returns the line
 */
char	*ft_get_line(char *conserve)
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
char	*ft_save(char *conserve)
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
