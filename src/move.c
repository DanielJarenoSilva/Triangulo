/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:49:38 by djareno           #+#    #+#             */
/*   Updated: 2026/03/09 11:19:53 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_y(t_player *p, t_map *map, double speed)
{
	int	x;
	int	y;

	x = (int)(p->pos_x + p->dir_x * speed);
	y = (int)(p->pos_y + p->dir_y * speed);
	if (x < map->width && x >= 0
		&& (int)p->pos_y >= 0 && p->pos_y < map->height
		&& map->map[(int)p->pos_y][x] != '1')
		p->pos_x += p->dir_x * speed;
	if (y < map->height && y >= 0
		&& (int)p->pos_x >= 0 && (int)p->pos_x < map->width
		&& map->map[y][(int)p->pos_x] != '1')
		p->pos_y += p->dir_y * speed;
}

void	move_x(t_player *p, t_map *map, double speed)
{
	int	x;
	int	y;

	x = (int)(p->pos_x + p->plane_x * speed);
	y = p->pos_y;
	if (y >= 0 && y < map->height
		&& x >= 0 && x < map->width
		&& map->map[y][x] != '1')
	{
		p->pos_x -= p->dir_y * speed;
	}
}

void	rotate(t_player *p, double speed)
{
	double	old_dir;
	double	len;

	old_dir = p->dir_x;
	p->dir_x = p->dir_x * cos(speed) - p->dir_y * sin(speed);
	p->dir_y = old_dir * sin(speed) + p->dir_y * cos(speed);
	len = sqrt(p->dir_x * p->dir_x + p->dir_y * p->dir_y);
	p->dir_x /= len;
	p->dir_y /= len;
	p->plane_x = -p->dir_y * 0.66;
	p->plane_y = p->dir_x * 0.66;
}
