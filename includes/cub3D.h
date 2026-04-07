/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:57:35 by lvargas-          #+#    #+#             */
/*   Updated: 2026/04/07 19:45:32 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./get_next_line.h"
# include "MLX42/MLX42.h"
# include <math.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 600
# define WIDTH 800
# define TEX_WIDTH 64
# define TEX_HEIGHT 64
# define TEX_NORTH 0
# define TEX_SOUTH 1
# define TEX_EAST 2
# define TEX_WEST 3

typedef struct s_path
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				f[3];
	int				c[3];
}					t_path;

typedef struct t_player
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
}					t_player;

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
	mlx_image_t		*img;
	mlx_texture_t	*wall_tex[4];
	t_path			*path;
}					t_raycast;

typedef struct s_wall
{
	double			dw;
	double			wall_x;
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
	uint32_t		color;
	uint8_t			*texture;
}					t_wall;

typedef struct t_map
{
	int				height;
	int				width;
	char			**map;
}					t_map;

typedef struct s_parse
{
	int				no;
	int				so;
	int				we;
	int				ea;
	int				f;
	int				c;
}					t_parse;

typedef struct s_global
{
	t_parse			*parse;
	t_path			*path;
	int				line_map_begin;
	mlx_t			*mlx;
	t_raycast		ray;
	t_player		player;
	t_map			*map;
}					t_global;

int					ft_strcmp(char *s1, char *s2);
int					ft_isdigit(int c);
void				*ft_memset(void *s, int c, size_t n);
int					ft_atoi(const char *nptr);
char				*ft_strncpy(char *dest, const char *src, int n);
void				print_errors_1(int error);
void				print_errors_2(int error);
int					check_parse_errors(char *filename, int fd,
						t_global *global);
char				*get_word(char *line, int nb);
int					check_all_ids(t_global *global);
t_global			*init_struct(void);
int					has_cub_extension(char *filename);
void				save_paths(char *line, char *word, t_global *global);
int					get_lenght(char *line, int n);
void				free_struct(t_global *global);
void				save_single_color(t_global *global, char *id, int i, int n);
void				read_and_save_map(char *filename, t_global *global);
int					check_map(t_global *global);
int					check_map_line(t_global *global, int *char_flag, int n,
						int m);
int					check_double_id(t_global *global, char *word);
int					check_path(char *line);
void				find_player(t_player *player, t_map *map);
void				cube(t_global *game);
void				move_x(t_player *p, t_map *map, double speed);
void				raycast(t_player *player, t_map *map, t_raycast *ray);
void				move_y(t_player *p, t_map *map, double speed);
void				rotate(t_player *p, double speed);
void				put_pixel(mlx_image_t *img, int x, int y, uint32_t color);
void				draw_wall_aux(t_raycast *r, t_wall *w, int x);
int					check_errors_and_save_map(t_global *global, int fd,
						char *file_name);

#endif