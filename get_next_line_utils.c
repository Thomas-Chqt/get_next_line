/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:15:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/10 11:54:14 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*append_buff(char *str, void const *buff, size_t buff_len)
{
	char	*output_str;
	size_t	i;
	size_t	y;

	output_str = malloc(sizeof(char) * (gnl_strlen(str) + buff_len + 1));
	i = 0;
	while (str && str[i])
	{
		output_str[i] = str[i];
		i++;
	}
	y = 0;
	while (y < buff_len)
		output_str[i++] = ((char *)buff)[y++];
	output_str[i] = '\0';
	free(str);
	return (output_str);
}

size_t	first_index(unsigned char value, void *buffer, size_t buffer_len)
{
	size_t	i;

	i = 0;
	while (i < buffer_len)
	{
		if (((unsigned char *)buffer)[i] == value)
			return (i);
		i++;
	}
	return (i - 1);
}

void	memmove_zero(void *dst, void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		((unsigned char *)src)[i] = 0;
		i++;
	}
}
