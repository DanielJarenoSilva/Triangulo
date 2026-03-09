/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:56:28 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/09 20:27:07 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3D.h"

int	has_cub_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}

void check_and_save_identifiers(char *line, int *map_flag)
{
	char *word;
	
	word = get_word(line, 1);
	if (!word)
		return;
	else if (word[0] == '1' || word[0] == '0')
	{
		map_flag = 1;
		free(word);
		return;
	}
	// guardar los ids en una struct
}

int check_file(int fd, t_parse *parse)
{
	int map_flag;
	char *line;
	char *word;

	map_flag = 0;
	while (!map_flag)
	{
		line = get_next_line(fd, 0);
		check_and_save_identifiers(line, &map_flag);
		if (map_flag == 1)
		{
			if (check_all_ids(&parse) == 0)
			{
				print_errors_1(4);
				exit(1);
			}
		}
	}
}

void	check_errors_1(char *filename, int fd, t_parse *parse)
{
	if (has_cub_extension(filename) == 0)
	{
		print_errors_1(3);
		exit(1);
	}
}