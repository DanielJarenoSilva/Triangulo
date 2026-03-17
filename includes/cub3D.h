/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:57:35 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/17 21:22:36 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_parse
{
	int		NO;
	int		SO;
	int		WE;
	int		EA;
	int		F;
	int		C;
}			t_parse;

typedef struct s_path
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	int		F[3];
	int		C[3];
}			t_path;

typedef struct s_global
{
	t_parse	*parse;
	t_path	*path;
	int 	line_map_begin;
	char 	**map;
	int 	map_width;
	int 	map_height;
}			t_global;

int			ft_strcmp(char *s1, char *s2);
int			ft_isdigit(int c);
int			ft_atoi(const char *nptr);
char		*ft_strncpy(char *dest, const char *src, int n);
void		print_errors_1(int error);
int			check_parse_errors(char *filename, int fd, t_global *global);
char		*get_word(char *line, int nb);
int			check_all_ids(t_global *global);
t_global	*init_struct(void);
int			has_cub_extension(char *filename);
void		save_paths(char *line, char *word, t_global *global);
int			get_lenght(char *line, int n);
void 		free_struct(t_global *global);
void 		save_single_color(t_global *global, char *id, int i, int n);
void		read_map(char *filename, t_global *global);

#endif