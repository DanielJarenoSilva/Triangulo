/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:09:34 by lvargas-          #+#    #+#             */
/*   Updated: 2026/04/07 20:00:15 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_parse(t_global *global)
{
	global->parse->no = 0;
	global->parse->so = 0;
	global->parse->we = 0;
	global->parse->ea = 0;
	global->parse->f = 0;
	global->parse->c = 0;
	global->map->width = 0;
	global->map->height = 0;
	global->map->map = NULL;
	global->line_map_begin = 0;
}

void	init_path(t_path *path)
{
	path->no = NULL;
	path->so = NULL;
	path->we = NULL;
	path->ea = NULL;
	path->f[0] = -1;
	path->f[1] = -1;
	path->f[2] = -1;
	path->c[0] = -1;
	path->c[1] = -1;
	path->c[2] = -1;
}

int	init_struct_1(t_global *global, t_parse *parse, t_path *path)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	if (!map)
		return (1);
	global->map = map;
	global->parse = parse;
	global->path = path;
	init_parse(global);
	init_path(global->path);
	return (0);
}

t_global	*init_struct(void)
{
	t_global	*global;
	t_parse		*parse;
	t_path		*path;

	global = malloc(sizeof(*global));
	if (!global)
		return (NULL);
	parse = malloc(sizeof(*parse));
	if (!parse)
	{
		free(global);
		return (NULL);
	}
	path = malloc(sizeof(*path));
	if (!path)
	{
		free(parse);
		free(global);
		return (NULL);
	}
	if (init_struct_1(global, parse, path) == 1)
		return (free(path), free(parse), free(global), NULL);
	return (global);
}
