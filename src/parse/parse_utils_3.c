/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:56:35 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/18 16:17:58 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

void save_single_color(t_global *global, char *id, int i, int n)
{
	if (ft_strcmp(id, "F") == 0)
	{
		global->parse->F = 1;
		global->path->F[i - 1] = n;
	}
	else if (ft_strcmp(id, "C") == 0)
	{
		global->parse->C = 1;
		global->path->C[i - 1] = n;
	}
}

int check_double_id(t_global *global, char *word)
{
	if (ft_strcmp(word, "NO") == 0 && global->parse->NO == 1)
		return (print_errors_2(1), -1);
	else if (ft_strcmp(word, "SO") == 0 && global->parse->SO == 1)
		return (print_errors_2(1), -1);
	else if (ft_strcmp(word, "WE") == 0 && global->parse->WE == 1)
		return (print_errors_2(1), -1);
	else if (ft_strcmp(word, "EA") == 0 && global->parse->EA == 1)
		return (print_errors_2(1), -1);
	else if (ft_strcmp(word, "F") == 0 && global->parse->F == 1)
		return (print_errors_2(1), -1);
	else if (ft_strcmp(word, "C") == 0 && global->parse->C == 1)
		return (print_errors_2(1), -1);
	return (0);
}

int check_path(char *line)
{
	char *path;
	int fd;
	
	path = get_word(line, 2);
	if (!path)
		return (free(path), print_errors_2(2), -1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (free(path), print_errors_2(3), -1);
	return (0);
}
