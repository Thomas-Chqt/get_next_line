/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:48:56 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/02 22:35:23 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*free_str(char *str);
static void		reset_buffer(char *buffer, size_t len);
static size_t	first_index(char c, char buffer[], size_t len);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE] = {};
	char		*str;
	ssize_t		read_len;

	str = ft_substr("", 0, 0);
	while (str && str[ft_strlen(str) - 1] != '\n')
	{
		read_len = read(fd, buffer + ft_strlen(buffer),
				BUFFER_SIZE - ft_strlen(buffer));
		if (read_len < 0)
			return (free_str(str));
		str = ft_strjoin(str, ft_substr(buffer, 0, first_index('\n',
						buffer, ft_strlen(buffer)) + 1));
		reset_buffer(buffer, ft_strlen(buffer));
		if (str[0] == '\0')
			return (free_str(str));
		else if (read_len == 0)
			return (str);
	}
	return (str);
}

static char	*free_str(char *str)
{
	if (str)
		free(str);
	return (NULL);
}

static void	reset_buffer(char *buffer, size_t len)
{
	size_t	i;
	size_t	n_index;

	if (len == 0)
		return ;
	i = 0;
	n_index = first_index('\n', buffer, len);
	while (i <= n_index)
		buffer[i++] = 0;
	ft_memmove(buffer,
		buffer + n_index + 1,
		len - (n_index + 1));
}

static size_t	first_index(char c, char buffer[], size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (buffer[i] == c)
			return (i);
		i++;
	}
	return (len - 1);
}
