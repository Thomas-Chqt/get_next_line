/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:48:56 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/01 22:22:17 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	size_t	str_len;
	char	buffer[BUFFER_SIZE];
	size_t	read_len;

	str_len = 1;
	str = malloc(sizeof(char) * str_len);
	read_len = 1;
	while (str && read_len > 0 && str[str_len - 2] != '\n')
	{
		read_len = read(fd, buffer, 1024);
		if (read_len < 0)
		{
			free(str);
			return (NULL);
		}
		str = realloc(str, str_len + read_len);
		if (str != NULL)
			memcpy(str + (str_len - 1), buffer, read_len);
		str_len += read_len;
	}
	if (str != NULL)
		str[str_len - 1] = '\0';
	return (str);
}
