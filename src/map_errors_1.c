/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:56:28 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/17 14:04:47 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

int check_color_format(char *colors)
{
	int i;
	int coma_count;
	int color_count;

	coma_count = 0;
	color_count = 0;
	i = 0;
	while (colors[i])
	{
		if (!ft_isdigit(colors[i]) && colors[i] != ',')
			return (print_errors_1(5), -1);
		if ((ft_isdigit(colors[i]) && i == 0) || (ft_isdigit(colors[i]) && !ft_isdigit(colors[i - 1])))
			color_count++;
		if (colors[i] == ',')
			coma_count++;
		i++;
	}
	if (coma_count != 2 || color_count != 3)
		return (print_errors_1(5), -1);
	return (0);
}

int get_nb_len(char *colors, int i)
{
	int len;

	len = 0;
	while (colors[i] != '\0' && colors[i] != ',')
	{
		len++;
		i++;	
	}
	return (len);
}

int check_color_range(int n)
{
	if (n < 0 || n > 255)
		return (print_errors_1(5), -1);
	return (0);
}

int get_color(char *colors, int n)
{
	int i;
	char *nb;
	int j;
	int number;
	
	if (check_color_format(colors) == -1)
		return (-1);
	i = 0;
	while (n != 1)
	{
		if (colors[i] == ',')
			n--;
		i++;
	}
	nb = (char *)malloc(get_nb_len(colors, i) * sizeof(char));
	j = 0;
	while (colors[i] != '\0' && colors[i] != ',')
	{
		nb[j] = colors[i];
		j++;
		i++;
	}
	nb[j] = '\0';
	number = ft_atoi(nb);
	if (check_color_range(number) == -1)
		return (free(nb), -1);
	return (free(nb), number);
}

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
		if (ft_strcmp(identifier, "F") == 0)
		{
			global->parse->F = 1;
			global->path->F[i - 1] = n;
		}
		else if (ft_strcmp(identifier, "C") == 0)
		{
			global->parse->C = 1;
			global->path->C[i - 1] = n;
		}
		i++;
	}
	return (free(identifier), free(rgb), 0);
}
	
int save_ids(char *line, char *word, t_global *global)
{
	if (ft_strcmp(word, "NO") == 0 || ft_strcmp(word, "SO") == 0 || ft_strcmp(word, "WE") == 0 || ft_strcmp(word, "EA") == 0)
	{
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

int	check_errors_1(char *filename, int fd, t_global *global)
{
	if (has_cub_extension(filename) == 0)
	{
		print_errors_1(3);
		exit(1);
	}
	if (check_file(fd, global) == -1)
	{
		free_struct(global);
		return (-1);
	}
	return (0);
}