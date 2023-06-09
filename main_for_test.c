/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:47:06 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/09 15:23:12 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <libc.h>

int main()
{
	char	*line;
	int		fd;
	fd = open("test.txt", O_RDONLY);;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("len:[%ld]: %s", gnl_strlen(line), line);
		free(line);
	}
	close(fd);
	return 0;
}
