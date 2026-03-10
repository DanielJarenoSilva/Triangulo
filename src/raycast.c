/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:58:03 by djareno           #+#    #+#             */
/*   Updated: 2026/03/10 13:07:15 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_raycast(t_raycast *raycast, int x, t_player *player)
{
	raycast->camera_x = 2 * x / (double)WIDTH - 1.0;
	raycast->ray_dir_x = player->dir_x + player->plane_x * raycast->camera_x;
	raycast->ray_dir_y = player->dir_y + player->plane_y * raycast->camera_x;
	raycast->map_x = (int)player->pos_x;
	raycast->map_y = (int)player->pos_y;
	if (raycast->ray_dir_x == 0)
		raycast->delta_dist_x = 1e30;
	else
		raycast->delta_dist_x = fabs(1 / raycast->ray_dir_x);
	if (raycast->ray_dir_y == 0)
		raycast->delta_dist_y = 1e30;
	else
		raycast->delta_dist_y = fabs(1 / raycast->ray_dir_y);
	raycast->hit = 0;
}

void	init_step(t_raycast *r, t_player *player)
{
	if (r->ray_dir_x < 0)
	{
		r->step_x = -1;
		r->side_dist_x = (player->pos_x - r->map_x) * r->delta_dist_x;
	}
	else
	{
		r->step_x = 1;
		r->side_dist_x = (r->map_x + 1.0 - player->pos_x) * r->delta_dist_x;
	}
	if (r->ray_dir_y < 0)
	{
		r->step_y = -1;
		r->side_dist_y = (player->pos_y - r->map_y) * r->delta_dist_y;
	}
	else
	{
		r->step_y = 1;
		r->side_dist_y = (r->map_y + 1.0 - player->pos_y) * r->delta_dist_y;
	}
}

void	dda(t_raycast *r, t_map *map)
{
	while (!r->hit)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->map_x += r->step_x;
			r->side = 0;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->map_y += r->step_y;
			r->side = 1;
		}
		if (r->map_x < 0 || r->map_x >= map->width
			|| r->map_y < 0 || r->map_y >= map->height)
		{
			r->hit = 1;
			return ;
		}
		if (map->map[r->map_y][r->map_x] == '1')
			r->hit = 1;
	}
}

void	draw_wall(t_raycast *r, t_player *p, int x)
{
	t_wall	w;
	double	pwd;

	if (r->side == 0)
		pwd = (r->map_x - p->pos_x + (1 - r->step_x) / 2) / r->ray_dir_x;
	else
		pwd = (r->map_y - p->pos_y + (1 - r->step_y) / 2) / r->ray_dir_y;
	if (pwd < 0.0001)
		pwd = 0.0001;
	w.line_height = (int)(HEIGHT / pwd);
	w.draw_start = -w.line_height / 2 + HEIGHT / 2;
	if (w.draw_start < 0)
		w.draw_start = 0;
	w.draw_end = w.line_height / 2 + HEIGHT / 2;
	if (w.draw_end >= HEIGHT)
		w.draw_end = HEIGHT - 1;
	if (r->side == 0)
		w.wall_x = p->pos_y + pwd * r->ray_dir_y;
	else
		w.wall_x = p->pos_x + pwd * r->ray_dir_x;
	w.wall_x -= floor(w.wall_x);
	w.tex_x = (int)(w.wall_x * (double)TEX_WIDTH);
	draw_wall_aux(r, &w, x);
}

void	raycast(t_player *player, t_map *map, t_raycast *ray)
{
	int			x;

	x = 0;
	ft_memset(ray->img->pixels, 0, WIDTH * HEIGHT * 4);
	while (x < WIDTH)
	{
		init_raycast(ray, x, player);
		init_step(ray, player);
		dda(ray, map);
		draw_wall(ray, player, x);
		x++;
	}
}
