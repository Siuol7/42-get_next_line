/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:48:18 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/25 15:51:10 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

int		ft_strlen(char *str);
int		ft_strchr(char *buffer, char c);

char	*get_next_line(int fd);
char	*ft_strncpy(char *dest, char *src, unsigned int len);
char	*ft_substring(char *main_buffer, int start, int end);
char	*ft_buffer_join(char *main_buffer, char *sub_buffer);
char	*ft_free(char **buffer);

#endif