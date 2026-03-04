/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:38:42 by djareno           #+#    #+#             */
/*   Updated: 2026/03/04 10:42:26 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	n(t_player *player, t_map *map, int x, int y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	map->map[y][x] = '0';
	player->dir_x = 0;
	player->dir_y = -1;
	player->plane_x = 0.66;
	player->plane_y = 0;
}

void	s(t_player *player, t_map *map, int x, int y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	map->map[y][x] = '0';
	player->dir_x = 0;
	player->dir_y = 1;
	player->plane_x = -0.66;
	player->plane_y = 0;
}

void	e(t_player *player, t_map *map, int x, int y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	map->map[y][x] = '0';
	player->dir_x = 1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = 0.66;
}

void	w(t_player *player, t_map *map, int x, int y)
{
	player->pos_x = x + 0.5;
	player->pos_y = y + 0.5;
	map->map[y][x] = '0';
	player->dir_x = -1;
	player->dir_y = 0;
	player->plane_x = 0;
	player->plane_y = -0.66;
}

void	find_player(t_player *player, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x] == 'N')
				n(player, map, x, y);
			if (map->map[y][x] == 'S')
				s(player, map, x, y);
			if (map->map[y][x] == 'E')
				e(player, map, x, y);
			if (map->map[y][x] == 'W')
				w(player, map, x, y);
			x++;
		}
		y++;
	}
}
