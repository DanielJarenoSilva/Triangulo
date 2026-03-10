/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 20:09:34 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/10 12:56:26 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_parse(t_parse *parse)
{
	parse->NO = 0;
	parse->SO = 0;
	parse->WE = 0;
	parse->EA = 0;
	parse->F = 0;
	parse->C = 0;
}

void	init_path(t_path *path)
{
	path->NO = NULL;
	path->SO = NULL;
	path->WE = NULL;
	path->EA = NULL;
	path->F[0] = -1;
	path->F[1] = -1;
	path->F[2] = -1;
	path->C[0] = -1;
	path->C[1] = -1;
	path->C[2] = -1;
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
	global->parse = parse;
	global->path = path;
	init_parse(global->parse);
	init_path(global->path);
	return (global);
}
