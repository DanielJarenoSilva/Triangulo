/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:55:49 by djareno           #+#    #+#             */
/*   Updated: 2026/04/07 20:01:08 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	update(void *param)
{
	t_global	*g;

	if (!param)
		return ;
	g = param;
	if (!g->mlx)
		return ;
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
		move_y(&g->player, g->map, 0.05);
	if (mlx_is_key_down(g->mlx, MLX_KEY_S))
		move_y(&g->player, g->map, -0.05);
	if (mlx_is_key_down(g->mlx, MLX_KEY_D))
		move_x(&g->player, g->map, 0.05);
	if (mlx_is_key_down(g->mlx, MLX_KEY_A))
		move_x(&g->player, g->map, -0.05);
	if (mlx_is_key_down(g->mlx, MLX_KEY_RIGHT))
		rotate(&g->player, 0.05);
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT))
		rotate(&g->player, -0.05);
	if (mlx_is_key_down(g->mlx, MLX_KEY_ESCAPE))
		exit(1);
	raycast(&g->player, g->map, &g->ray);
}

void	cube(t_global *game)
{
	find_player(&game->player, game->map);
	game->mlx = mlx_init(WIDTH, HEIGHT, "cube3D", false);
	if (!game->mlx)
		return ;
	game->ray.wall_tex[TEX_NORTH] = mlx_load_png(game->path->no);
	game->ray.wall_tex[TEX_SOUTH] = mlx_load_png(game->path->so);
	game->ray.wall_tex[TEX_EAST] = mlx_load_png(game->path->ea);
	game->ray.wall_tex[TEX_WEST] = mlx_load_png(game->path->we);
	game->ray.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->ray.img, 0, 0);
	mlx_loop_hook(game->mlx, update, game);
	mlx_loop(game->mlx);
	mlx_delete_texture(game->ray.wall_tex[TEX_NORTH]);
	mlx_delete_texture(game->ray.wall_tex[TEX_SOUTH]);
	mlx_delete_texture(game->ray.wall_tex[TEX_EAST]);
	mlx_delete_texture(game->ray.wall_tex[TEX_WEST]);
	mlx_terminate(game->mlx);
}
