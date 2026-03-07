/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 12:55:49 by djareno           #+#    #+#             */
/*   Updated: 2026/03/07 17:36:15 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	update(void *param)
{
	t_game	*g;

	g = param;
	if (mlx_is_key_down(g->mlx, MLX_KEY_W))
		move_y(&g->player, &g->map, 0.05);
	if (mlx_is_key_down(g->mlx, MLX_KEY_S))
		move_y(&g->player, &g->map, -0.05);
	if (mlx_is_key_down(g->mlx, MLX_KEY_D))
		move_x(&g->player, &g->map, 0.05);
	if (mlx_is_key_down(g->mlx, MLX_KEY_A))
		move_x(&g->player, &g->map, -0.05);
	if (mlx_is_key_down(g->mlx, MLX_KEY_RIGHT))
		rotate(&g->player, -0.05);
	if (mlx_is_key_down(g->mlx, MLX_KEY_LEFT))
		rotate(&g->player, -0.05);
	raycast(&g->player, &g->map, &g->ray);
}

void	cube(t_map *map)
{
	t_game			game;

	game.map = *map;
	find_player(&game.player, map);
	game.mlx = mlx_init(WIDTH, HEIGHT, "cube3D", false);
	if (!game.mlx)
		return ;
	game.ray.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game.mlx, game.ray.img, 0, 0);

	mlx_loop_hook(game.mlx, update, &game);

	mlx_loop(game.mlx);
	mlx_terminate(game.mlx);
}
