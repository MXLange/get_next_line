/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msprenge <msprenge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:38:39 by msprenge          #+#    #+#             */
/*   Updated: 2022/11/22 14:15:02 by msprenge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
//#include <fcntl.h>

char	*erase_first_line(char *file)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	temp = ft_calloc((ft_strlen(file) - i), sizeof(char));
	i++;
	j = 0;
	while (file[i])
		temp[j++] = file[i++];
	free(file);
	return (temp);
}

char	*get_first_line(char *file)
{
	char	*first_line;
	size_t	i;

	i = 0;
	if (!file[i])
		return (NULL);
	while (file[i] && file[i] != '\n')
		i++;
	first_line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (file[i] && file[i] != '\n')
	{
		first_line[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
		first_line[i] = '\n';
	return (first_line);
}

char	*ft_free(char *file, char *temp)
{
	char	*final;

	final = ft_strjoin(file, temp);
	free(file);
	return (final);
}

char	*make_file(int fd, char *file)
{
	char	*temp;
	ssize_t	read_bytes;

	if (!file)
		file = ft_calloc(1, 1);
	if (ft_strchr(file, '\n'))
		return (file);
	temp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, temp, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(temp);
			free(file);
			return (NULL);
		}
		temp[read_bytes] = 0;
		file = ft_free(file, temp);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	free(temp);
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	file = make_file(fd, file);
	if (!file)
		return (NULL);
	line = get_first_line(file);
	file = erase_first_line(file);
	return (line);
}
/*
int	main(void)
{
	char	*line;
	//char	*line2;
	int		i;
	int		fd1;
	int		fd2;
	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	i = 0;
	while (i < 6)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line2 = get_next_line(fd2);
		printf("line [%02d]: %s", i, line2);
		free(line2);
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}*/
