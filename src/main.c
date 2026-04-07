/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:54:26 by lvargas-          #+#    #+#             */
/*   Updated: 2026/04/07 10:36:02 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

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
	global->ray.path = global->path;
	cube(global);
	free_struct(global);
	return (0);
}
