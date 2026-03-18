/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:54:26 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/18 19:34:58 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

#include <stdio.h>

void	print_map_debug(t_global *global)
{
    int	y;

    if (!global || !global->map)
    {
        printf("map: NULL\n");
        return ;
    }
    printf("map_height=%d map_width=%d line_map_begin=%d\n",
        global->map_height, global->map_width, global->line_map_begin);
    y = 0;
    while (global->map[y])
    {
        printf("[%02d] \"%s\"\n", y, global->map[y]);
        y++;
    }
}

int	main(int argc, char *argv[])
{
	char		*file_name;
	t_global	*global;
	int			fd;

	if (argc != 2)
		return (print_errors_1(1), 1);
	file_name = argv[1];
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (close(fd), print_errors_1(2), 1);
	global = init_struct();
	if (check_parse_errors(file_name, fd, global) == -1)
	{
		free_struct(global);
		get_next_line(fd, 1);
		close(fd);
		return (1);
	}
	get_next_line(fd, 1);
	read_and_save_map(file_name, global);
	if (check_map(global) == -1)
	{
		free_struct(global);
		get_next_line(fd, 1);
		close(fd);
		return (1);
	}
	get_next_line(fd, 1);
	close(fd);
	free_struct(global);
	return (0);
}
