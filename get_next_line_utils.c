/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caonguye <caonguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 02:05:35 by caonguye          #+#    #+#             */
/*   Updated: 2024/11/20 03:41:46 by caonguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strncpy(char *dest, char *src, unsigned int len)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < len)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < len)
		dest[i++] = '\0';
	return (dest);
}

int	ft_strchr(char *main_buffer, char c)
{
	unsigned int	i;

	i = 0;
	while (main_buffer[i])
	{
		if (main_buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_buffer_join(char *main_buffer, char *sub_buffer)
{
	size_t	total;
	size_t	main_len;
	size_t	sub_len;
	char	*final;

	if (!main_buffer)
	{
		main_buffer = malloc(1);
		if (!main_buffer)
			return (NULL);
		main_buffer[0] = '\0';
	}
	total = 0;
	main_len = ft_strlen(main_buffer);
	sub_len = ft_strlen(sub_buffer);
	total = main_len + sub_len;
	final = malloc(total + 1);
	if (!final)
		return (ft_free(&main_buffer));
	ft_strncpy(final, main_buffer, main_len);
	ft_strncpy(final + main_len, sub_buffer, sub_len);
	final[main_len + sub_len] = '\0';
	ft_free(&main_buffer);
	return (final);
}

char	*ft_substring(char *main_buffer, int start, int end)
{
	char	*result;
	int		total;
	int		i;

	if (!main_buffer)
		return (NULL);
	if (start >= ft_strlen(main_buffer))
		total = 0;
	else
		total = end - start;
	result = malloc(total + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (start < end)
	{
		result[i] = main_buffer[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
