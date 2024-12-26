/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 07:02:36 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/25 19:51:00 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

static char	*reset_buffer(char *buffer)
{
	char	*temp;
	int		newline;

	if (!buffer)
		return (NULL);
	newline = 0;
	while (buffer[newline] && buffer[newline] != '\n')
		newline++;
	if (buffer[newline] == '\n')
		newline++;
	temp = ft_substring(buffer, newline, ft_strlen(buffer));
	if (!temp)
		return (ft_free(&buffer));
	ft_free(&buffer);
	return (temp);
}

static char	*get_line(char *buffer)
{
	char	*temp_line;
	int		newline;

	if (!buffer || !(*buffer))
		return (NULL);
	newline = 0;
	while (buffer[newline] && buffer[newline] != '\n')
		newline++;
	if (buffer[newline] == '\n')
		newline++;
	temp_line = ft_substring(buffer, 0, newline);
	if (!temp_line)
		return (NULL);
	return (temp_line);
}

static char	*update_buffer(char *buffer, int fd)
{
	char	*sub_buffer;
	int		readbytes;

	sub_buffer = malloc(BUFFER_SIZE + 1);
	if (!sub_buffer)
		return (NULL);
	readbytes = 1;
	while ((buffer && !ft_strchr(buffer, '\n') && readbytes > 0) || !buffer)
	{
		readbytes = read(fd, sub_buffer, BUFFER_SIZE);
		if (!sub_buffer)
			return (ft_free(&buffer));
		if (readbytes < 0)
		{
			free(sub_buffer);
			return (ft_free(&buffer));
		}
		if (readbytes == 0)
			break ;
		sub_buffer[readbytes] = '\0';
		buffer = ft_buffer_join(buffer, sub_buffer);
	}
	free(sub_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer[OPEN_MAX];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || OPEN_MAX < fd)
		return (NULL);
	buffer[fd] = update_buffer(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	if (!line)
		ft_free(&buffer[fd]);
	buffer[fd] = reset_buffer(buffer[fd]);
	return (line);
}
