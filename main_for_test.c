/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_for_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchoquet <tchoquet@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 21:47:06 by tchoquet          #+#    #+#             */
/*   Updated: 2023/06/01 22:20:04 by tchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(int argc, char const *argv[])
{
	int fd = open("test.txt", O_RDONLY);

	char *line = get_next_line(fd);

	return 0;
}
