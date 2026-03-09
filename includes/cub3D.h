/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:57:35 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/09 10:48:08 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <MLX42/MLX42.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "./get_next_line.h"

# define HEIGHT 600
# define WIDTH 800

typedef struct t_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
}				t_player;

typedef struct t_map
{
	int		height;
	int		width;
	char	**map;
}			t_map;

typedef struct t_raycast
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			side_dist_x;
	double			side_dist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	mlx_image_t*	img;
}				t_raycast;

typedef struct t_game
{
	mlx_t		*mlx;
	t_player	player;
	t_map		map;
	t_raycast	ray;
}			t_game;

int		ft_strcmp(char *s1, char *s2);
void	*ft_memset(void *s, int c, size_t n);
void	print_errors_1(int error);
void	check_errors_1(char *filename);
void	find_player(t_player *player, t_map *map);
void	cube(t_map *map);
void	move_x(t_player *p, t_map *map, double speed);
void	raycast(t_player *player, t_map *map, t_raycast *ray);
void	move_y(t_player *p, t_map *map, double speed);
void	rotate(t_player *p, double speed);

#endif