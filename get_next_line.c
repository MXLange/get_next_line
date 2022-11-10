/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msprenge <msprenge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:38:39 by msprenge          #+#    #+#             */
/*   Updated: 2022/11/10 15:30:27 by msprenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*ft_free(char *buffer, char *buf)
{
	char	*final;

	final = ft_strjoin(buffer, buf);
	free(buffer);
	return (final);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	//buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(buffer, '\n'))
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		res = ft_free(res, buffer);
		//if (ft_strchr(buffer, '\n')) //colocar no while para testar;
		//	break;
	}
	free(buffer);
	return (res);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer && buffer[i] != '\n')
		i++;
	//line = ft_calloc((i + 2), sizeof(char));
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_remain_of_file(char *buffer)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (buffer && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	//rest = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	rest = malloc(sizeof(char) * (ft_strlen(buffer) - i + 1));
	if (!rest)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		rest[j++] = buffer[i++];
	free(buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*curr_line;
	static char	*buffer; //[OPEN_MAX] for bonnus

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	curr_line = ft_get_line(buffer);
	buffer = ft_remain_of_file(buffer);
	return (curr_line);
}
/*
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	//int		fd2;
	fd1 = open("tests/test.txt", O_RDONLY);
	//fd2 = open("tests/test2.txt", O_RDONLY);
	i = 0;
	while (i < 5)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		//line = get_next_line(fd2);
		//printf("line [%02d]: %s", i, line);
		//free(line);
		i++;
	}
	close(fd1);
	//close(fd2);
	return (0);
}*/
