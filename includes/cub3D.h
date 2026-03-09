/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:57:35 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/09 20:23:27 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_parse {
    int NO;
    int SO;
    int WE;
    int EA;
    int F;
    int C;
} t_parse;

int	    ft_strcmp(char *s1, char *s2);
void	print_errors_1(int error);
void	check_errors_1(char *filename, int fd, t_parse *parse);
char    *get_word(char *line, int nb);
void    init_parse(t_parse *parse);
int     check_all_ids(t_parse *parse);

#endif