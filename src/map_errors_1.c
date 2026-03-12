/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:56:28 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/12 13:09:25 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

/*void save_colors(t_global *global)
{
	
}*/
	
void save_ids(char *line, char *word, t_global *global)
{
	save_paths(line, word, global);
	//if (ft_strcmp(word, "F") == 0 || ft_strcmp(word, "C") == 0)
	//	save_colors(global);
	//else
		//dar error porque el id no es valido
}

void	check_and_save_identifiers(char *line, int *map_flag, t_global *global)
{
	char	*word;

	word = get_word(line, 1);
	if (!word)
		return ;
	else if (word[0] == '1' || word[0] == '0')
	{
		*map_flag = 1;
		free(word);
		return ;
	}
	free(word);
	word = get_word(line, 3);
	if (word)
	{
		print_errors_1(5);
		free(word);
		exit (1);
	}
	free(word);
	save_ids(line, get_word(line, 1), global);
}

void	check_file(int fd, t_global *global)
{
	int		map_flag;
	char	*line;

	map_flag = 0;
	while (!map_flag)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		check_and_save_identifiers(line, &map_flag, global);
		free(line);
		if (map_flag == 1)
		{
			if (check_all_ids(global) == 0)
			{
				print_errors_1(4);
				exit(1);
			}
		}
	}
}

void	check_errors_1(char *filename, int fd, t_global *global)
{
	if (has_cub_extension(filename) == 0)
	{
		print_errors_1(3);
		exit(1);
	}
	check_file(fd, global);
}