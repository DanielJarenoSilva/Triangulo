/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:56:35 by lvargas-          #+#    #+#             */
/*   Updated: 2026/04/07 19:52:03 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

void	save_single_color(t_global *global, char *id, int i, int n)
{
	if (ft_strcmp(id, "F") == 0)
	{
		global->parse->f = 1;
		global->path->f[i - 1] = n;
	}
	else if (ft_strcmp(id, "C") == 0)
	{
		global->parse->c = 1;
		global->path->c[i - 1] = n;
	}
}

int	check_double_id(t_global *global, char *word)
{
	if (ft_strcmp(word, "NO") == 0 && global->parse->no == 1)
		return (print_errors_2(1), -1);
	else if (ft_strcmp(word, "SO") == 0 && global->parse->so == 1)
		return (print_errors_2(1), -1);
	else if (ft_strcmp(word, "WE") == 0 && global->parse->we == 1)
		return (print_errors_2(1), -1);
	else if (ft_strcmp(word, "EA") == 0 && global->parse->ea == 1)
		return (print_errors_2(1), -1);
	else if (ft_strcmp(word, "F") == 0 && global->parse->f == 1)
		return (print_errors_2(1), -1);
	else if (ft_strcmp(word, "C") == 0 && global->parse->c == 1)
		return (print_errors_2(1), -1);
	return (0);
}

int	check_path(char *line)
{
	char	*path;
	int		fd;

	path = get_word(line, 2);
	if (!path)
		return (free(path), print_errors_2(2), -1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (free(path), print_errors_2(3), -1);
	free(path);
	return (0);
}

int	check_errors_and_save_map(t_global *global, int fd, char *file_name)
{
	if (check_parse_errors(file_name, fd, global) == -1)
	{
		free_struct(global);
		get_next_line(fd, 1);
		close(fd);
		return (1);
	}
	get_next_line(fd, 1);
	read_and_save_map(file_name, global);
	if (check_map(global) == -1)
	{
		free_struct(global);
		get_next_line(fd, 1);
		close(fd);
		return (1);
	}
	get_next_line(fd, 1);
	close(fd);
	return (0);
}

void	save_paths(char *line, char *word, t_global *global)
{
	if (ft_strcmp(word, "NO") == 0)
	{
		global->parse->no = 1;
		global->path->no = get_word(line, 2);
	}
	else if (ft_strcmp(word, "SO") == 0)
	{
		global->parse->so = 1;
		global->path->so = get_word(line, 2);
	}
	else if (ft_strcmp(word, "WE") == 0)
	{
		global->parse->we = 1;
		global->path->we = get_word(line, 2);
	}
	else if (ft_strcmp(word, "EA") == 0)
	{
		global->parse->ea = 1;
		global->path->ea = get_word(line, 2);
	}
}
