/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhopp <lhopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 12:19:16 by lhopp             #+#    #+#             */
/*   Updated: 2024/04/11 11:04:26 by lhopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define MAX_FD 1024

char	*create_new_line(char **line, int length)
{
	char	*new_line;

	new_line = malloc(sizeof(char) * (length + 1));
	if (new_line == NULL)
		return (NULL);
	if (*line != NULL)
	{
		ft_strcpy(new_line, *line);
		free(*line);
	}
	return (new_line);
}

void	append_line(char **line, const char *buffer)
{
	int		i;
	int		j;
	int		old_length;
	char	*new_line;

	old_length = 0;
	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (*line != NULL)
		old_length = (int)ft_strlen(*line);
	new_line = create_new_line(line, old_length + i);
	if (new_line == NULL)
		return ;
	while (j < i)
	{
		new_line[old_length + j] = buffer[j];
		j++;
	}
	new_line[old_length + j] = '\0';
	*line = new_line;
}

int	read_buffer(int fd, char **buffer)
{
	ssize_t	bytes_read;

	if (*buffer == NULL)
		*buffer = malloc(BUFFER_SIZE + 1);
	if (*buffer == NULL)
		return (0);
	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(*buffer);
		*buffer = NULL;
		return (0);
	}
	(*buffer)[bytes_read] = '\0';
	return (1);
}

char	*read_line_from_buffer(int fd, char **buffer, char **line)
{
	char const	*nlc;
	int			read_success;

	while (1)
	{
		if (buffer[fd] == NULL || ft_strlen(buffer[fd]) <= 0)
		{
			read_success = read_buffer(fd, &buffer[fd]);
			if (read_success == 0)
				return (*line);
		}
		nlc = ft_strchr(buffer[fd], '\n');
		if (nlc != NULL)
		{
			append_line(line, buffer[fd]);
			ft_memmove(buffer[fd], nlc + 1, ft_strlen(nlc));
			return (*line);
		}
		else
		{
			append_line(line, buffer[fd]);
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	line = NULL;
	if (fd < 0 || fd >= MAX_FD)
		return (line);
	return (read_line_from_buffer(fd, buffer, &line));
}
