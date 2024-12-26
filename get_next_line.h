/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:30:44 by caonguye          #+#    #+#             */
/*   Updated: 2024/12/06 16:23:04 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int		ft_strlen(char *str);
int		ft_strchr(char *buffer, char c);

char	*get_next_line(int fd);
char	*ft_strncpy(char *dest, char *src, unsigned int len);
char	*ft_substring(char *main_buffer, int start, int end);
char	*ft_buffer_join(char *main_buffer, char *sub_buffer);
char	*ft_free(char **buffer);

#endif