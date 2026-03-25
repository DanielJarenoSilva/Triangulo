/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:48:42 by djareno           #+#    #+#             */
/*   Updated: 2026/03/10 13:11:02 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	uint8_t	*pixel;

	pixel = (uint8_t *)&img->pixels[(y * img->width + x) * 4];
	*(uint32_t *)pixel = color;
}

void	draw(int x, t_raycast *r, t_wall *w)
{
	int	y;

	y = 0;
	while (y < w->draw_start)
	{
		put_pixel(r->img, x, y, 0xFFDFFF00);
		y++;
	}
	while (y < w->draw_end)
	{
		w->tex_y = (int)w->tex_pos & (TEX_HEIGHT - 1);
		w->tex_pos += w->step;
		w->color = *(uint32_t *)(w->texture
				+ (TEX_WIDTH * w->tex_y + w->tex_x) * 4);
		put_pixel(r->img, x, y, w->color);
		y++;
	}
	while (y < HEIGHT)
	{
		put_pixel(r->img, x, y, 0x444444FF);
		y++;
	}
}

void	draw_wall_aux(t_raycast *r, t_wall *w, int x)
{
	int		text_id;

	if (r->side == 0 && r->ray_dir_x > 0)
		w->tex_x = TEX_WIDTH - w->tex_x - 1;
	if (r->side == 1 && r->ray_dir_y < 0)
		w->tex_x = TEX_WIDTH - w->tex_x - 1;
	if (r->side == 0)
	{
		if (r->ray_dir_x > 0)
			text_id = TEX_WEST;
		else
			text_id = TEX_EAST;
	}
	else
	{
		if (r->ray_dir_y > 0)
			text_id = TEX_SOUTH;
		else
			text_id = TEX_NORTH;
	}
	w->texture = r->wall_tex[text_id]->pixels;
	w->step = 1.0 * TEX_HEIGHT / w->line_height;
	w->tex_pos = (w->draw_start - HEIGHT / 2 + w->line_height / 2) * w->step;
	draw(x, r, w);
}
