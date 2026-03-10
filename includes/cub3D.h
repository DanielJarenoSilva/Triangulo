/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:57:35 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/10 13:27:55 by lvargas-         ###   ########.fr       */
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
}			t_global;

int			ft_strcmp(char *s1, char *s2);
void		print_errors_1(int error);
void		check_errors_1(char *filename, int fd, t_global *global);
char		*get_word(char *line, int nb);
int			check_all_ids(t_global *global);
t_global	*init_struct(void);
int			has_cub_extension(char *filename);
void		save_paths(char *line, char *word, t_global *global);

#endif