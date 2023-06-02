/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:15:26 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/02 19:56:13 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*output_str;
	size_t	output_str_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	output_str_len = ft_strlen(s1) + ft_strlen(s2);
	output_str = malloc(sizeof(char) * (output_str_len + 1));
	if (!output_str)
		return (NULL);
	while (s1 != NULL && s1[i])
	{
		output_str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j])
	{
		output_str[i + j] = s2[j];
		j++;
	}
	output_str[i + j] = '\0';
	free(s1);
	free(s2);
	return (output_str);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*output_str;
	size_t	i;
	size_t	s_len;
	size_t	malloc_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < len)
		malloc_len = s_len;
	else
		malloc_len = len;
	output_str = malloc((malloc_len + 1) * sizeof(char));
	if (output_str == NULL)
		return (NULL);
	i = 0;
	while (((start + i) < s_len) && (s + start)[i] && i < len)
	{
		output_str[i] = (s + start)[i];
		i++;
	}
	output_str[i] = 0;
	return (output_str);
}

void	ft_memmove(void *dst, const void *src, size_t len)
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
