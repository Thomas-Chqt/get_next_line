/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:47:36 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/09 14:55:11 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	gnl_strlen(const char *s);
char	*append_buff(char *str, void const *buff, size_t buff_len);
size_t	first_index(unsigned char value, void *buffer, size_t buffer_len);
void	memmove_zero(void *dst, void *src, size_t src_len);

char	*get_next_line(int fd);

#endif