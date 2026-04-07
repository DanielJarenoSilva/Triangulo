/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:54:26 by lvargas-          #+#    #+#             */
/*   Updated: 2026/04/07 19:32:19 by lvargas-         ###   ########.fr       */
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
	if (check_errors_and_save_map(global, fd, file_name) == 1)
		return (1);
	global->ray.path = global->path;
	cube(global);
	free_struct(global);
	return (0);
}
