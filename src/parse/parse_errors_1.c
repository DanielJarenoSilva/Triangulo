/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:56:28 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/18 16:17:40 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

int save_colors(t_global *global, char *line)
{
	int n;
	int i;
	char *identifier;
	char *rgb;

	identifier = get_word(line, 1);
	rgb = get_word(line, 2);
	i = 1;
	while (i <= 3)
	{
		n = get_color(rgb, i);
		if (n == -1)
			return (free(identifier), free(rgb), -1);
		save_single_color(global, identifier, i, n);
		i++;
	}
	return (free(identifier), free(rgb), 0);
}

int save_ids(char *line, char *word, t_global *global)
{
	if (ft_strcmp(word, "NO") == 0 || ft_strcmp(word, "SO") == 0 || ft_strcmp(word, "WE") == 0 || ft_strcmp(word, "EA") == 0)
	{
		if (check_double_id(global, word) == -1)
			return (-1);
		if (check_path(line) == -1)
			return (-1);
		save_paths(line, word, global);
	}
	else if (ft_strcmp(word, "F") == 0 || ft_strcmp(word, "C") == 0)
	{
		if (save_colors(global, line) == -1)
			return (-1);
	}
	else
	{
		print_errors_1(7);
		return (-1);
	}
	return (0);
}

int	check_and_save_identifiers(char *line, int *map_flag, t_global *global)
{
	char	*word;

	word = get_word(line, 1);
	if (!word)
		return (0);
	else if (word[0] == '1' || word[0] == '0')
	{
		*map_flag = 1;
		free(word);
		return (0);
	}
	free(word);
	word = get_word(line, 3);
	if (word)
	{
		print_errors_1(5);
		free(word);
		return (-1);
	}
	free(word);
	word = get_word(line, 1);
	if (save_ids(line, word, global) == -1)
		return (free(word), -1);
	return (free(word), 0);
}

int	check_file(int fd, t_global *global)
{
	int		map_flag;
	char	*line;

	map_flag = 0;
	while (!map_flag)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		global->line_map_begin++;
		if (check_and_save_identifiers(line, &map_flag, global) == -1)
			return (free(line), -1);
		free(line);
		if (map_flag == 1)
		{
			if (check_all_ids(global) == 0)
				return (print_errors_1(4), -1);
		}
	}
	return (0);
}

int	check_parse_errors(char *filename, int fd, t_global *global)
{
	if (has_cub_extension(filename) == 0)
	{
		print_errors_1(3);
		exit(1);
	}
	if (check_file(fd, global) == -1)
	{
		return (-1);
	}
	return (0);
}
