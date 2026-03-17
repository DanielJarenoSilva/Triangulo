/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 18:45:22 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/17 21:23:20 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

void	get_width_and_height(int fd, t_global *global)
{
	char	*line;
	char	*tmp;
    int width;

    width = 0;
	line = get_next_line(fd, 0);
	while (line)
	{	
		(global->map_height)++;
        tmp = line;
		while (*line && *line != '\n')
		{
			width++;
			line++;
		}
        if (width > global->map_width)
            global->map_width = width;
        width = 0;
        line = get_next_line(fd, 0);
		free(tmp);
	}
	free(line);
}

char	**fill_matrix(int fd, int width, int height)
{
	char	*line;
	char	**map;
	int		y;

	map = (char **)malloc((height + 1) * sizeof(char **));
	if (!map)
		return (free(map), map = NULL, NULL);
	y = 0;
	while (y < height)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		map[y] = (char *)malloc((width + 1) * sizeof(char));
		if (!map[y])
			return (free(map), map = NULL, NULL);
		ft_strncpy(map[y], line, width);
		map[y][width] = '\0';
		free(line);
		y++;
	}
	while (y <= height)
        map[y++] = NULL;
	return (map);
}

void advance_until_map(t_global *global, int fd)
{
    int n;
    char *line;

    n = 0;
    while (n < (global->line_map_begin - 1))
    {
        line = get_next_line(fd, 0);
        (void)line;
        n++;
    }
}

void	read_map(char *filename, t_global *global)
{
	int		fd;

	fd = open(filename, O_RDONLY);
    advance_until_map(global, fd);
    get_width_and_height(fd, global);
    close(fd);
    fd = open(filename, O_RDONLY);
    advance_until_map(global, fd);
	global->map = fill_matrix(fd, global->map_width, global->map_height);
	close(fd);
}
