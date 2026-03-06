/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 10:58:03 by djareno           #+#    #+#             */
/*   Updated: 2026/03/06 12:41:54 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_raycast(t_raycast *raycast, int x, t_player *player)
{
	raycast->camera_x = 2 * x / (double)WIDTH -1;
	raycast->ray_dir_x = player->dir_x + player->plane_x * raycast->camera_x;
	raycast->ray_dir_y = player->dir_y + player->plane_y * raycast->camera_x;
	raycast->map_x = (int)player->pos_x;
	raycast->map_y = (int)player->pos_y;
	raycast->delta_dist_x = fabs(1 / (raycast->ray_dir_x + 1e-6));
	raycast->delta_dist_y = fabs(1 / (raycast->ray_dir_y + 1e-6));
	raycast->hit = 0;
}

void	cast(t_raycast *r, t_player *player)
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

void	ray_hit(t_raycast *raycast, t_map *map)
{
	while (raycast->hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (raycast->map_x < 0 || raycast->map_x >= map->width
			|| raycast->map_y < 0 || raycast->map_y >= map->height)
		{
			raycast->hit = 1;
			return ;
		}
		if (map->map[raycast->map_y][raycast->map_x] == '1')
			raycast->hit = 1;
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

void	put_pixel(t_raycast *r, t_player *p, int x)
{
	double	dw;
	int		line_height;
	int		draw_start;
	int		draw_end;

	if (r->side == 0)
		dw = (r->map_x - p->pos_x + (1 - r->step_x) / 2) / r->ray_dir_x;
	else
		dw = (r->map_y - p->pos_y + (1 - r->step_y) / 2) / r->ray_dir_y;
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
	ft_memset(ray->img->pixels, 0, WIDTH * HEIGHT * sizeof(int));
	while (x < WIDTH)
	{
		init_raycast(ray, x, player);
		cast(ray, player);
		ray_hit(ray, map);
		if (ray->hit)
			put_pixel(ray, player, x);
		x++;
	}
}
