/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:04:15 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/25 19:50:55 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = update_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	if (!line)
		ft_free(&buffer);
	buffer = reset_buffer(buffer);
	return (line);
}
