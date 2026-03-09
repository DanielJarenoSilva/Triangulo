/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:58:03 by djareno           #+#    #+#             */
/*   Updated: 2026/03/09 11:21:56 by djareno          ###   ########.fr       */
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

void	draw(int x, int draw_end, int ds, t_raycast *r)
{
	int			y;
	uint32_t	color;

	y = 0;
	while (y < ds)
	{
		mlx_put_pixel(r->img, x, y, 0x87CEEBFF);
		y++;
	}
	if (r->side == 1)
		color = 0xAAAAAAFF;
	else
		color = 0xFFFFFFFF;
	y = ds;
	while (y < draw_end)
	{
		mlx_put_pixel(r->img, x, y, color);
		y++;
	}
	y = draw_end;
	while (y < HEIGHT)
	{
		mlx_put_pixel(r->img, x, y, 0x444444FF);
		y++;
	}
}

void	draw_wall(t_raycast *r, int x)
{
	double	dw;
	int		line_height;
	int		draw_start;
	int		draw_end;

	if (r->side == 0)
		dw = r->side_dist_x - r->delta_dist_x;
	else
		dw = r->side_dist_y - r->delta_dist_y;
	if (dw < 0.0001)
		dw = 0.0001;
	line_height = (int)(HEIGHT / dw);
	draw_start = -line_height / 2 + HEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	draw(x, draw_end, draw_start, r);
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
		draw_wall(ray, x);
		x++;
	}
}
