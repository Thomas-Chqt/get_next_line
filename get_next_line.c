/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:48:56 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/10 14:28:57 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	reset_buffer(unsigned char *buffer, size_t len);
static char	*free_str(char *str);

char	*get_next_line(int fd)
{
	static unsigned char	buffer[BUFFER_SIZE];
	char					*line;
	ssize_t					read_len;

	line = append_buff(NULL, buffer,
			first_index((unsigned char) '\n', buffer, BUFFER_SIZE) + 1);
	if (line == NULL)
		return (NULL);
	reset_buffer(buffer, BUFFER_SIZE);
	while (line[0] == '\0' || line[gnl_strlen(line) - 1] != '\n')
	{
		read_len = read(fd, buffer, BUFFER_SIZE);
		if (read_len < 0)
			return (free_str(line));
		line = append_buff(line, buffer,
				first_index((unsigned char) '\n', buffer, read_len) + 1);
		if (line == NULL || line[0] == '\0')
			return (free_str(line));
		reset_buffer(buffer, read_len);
		if (read_len < BUFFER_SIZE)
			return (line);
	}
	return (line);
}

static void	reset_buffer(unsigned char *buffer, size_t len)
{
	size_t	i;
	size_t	n_index;

	if (len == 0)
		return ;
	i = 0;
	n_index = first_index((unsigned char) '\n', buffer, len);
	while (i <= n_index)
		buffer[i++] = 0;
	memmove_zero(buffer, buffer + n_index + 1, len - (n_index + 1));
}

static char	*free_str(char *str)
{
	free(str);
	return (NULL);
}
