/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:40:58 by lvargas-          #+#    #+#             */
/*   Updated: 2026/04/07 20:00:42 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_struct(t_global *global)
{
	if (!global)
		return ;
	if (global->map->map)
		free_map(global->map->map);
	free(global->map);
	if (global->path)
	{
		free(global->path->no);
		free(global->path->so);
		free(global->path->we);
		free(global->path->ea);
		free(global->path);
	}
	free(global->parse);
	free(global);
}
