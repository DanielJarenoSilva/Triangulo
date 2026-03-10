/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:43:19 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/10 13:27:45 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

int	get_lenght(char *line, int n)
{
	int	lenght;

	lenght = 0;
	while (line[n] != '\0' && line[n] != ' ')
	{
		lenght++;
		n++;
	}
	return (lenght);
}

char	*get_word(char *line, int nb)
{
	char	*word;
	int		i;
	int		lenght;
	int		n;

	n = 0;
	while (line[n] == ' ')
		n++;
	if (line[n] != '\0' && nb == 2)
	{
		while (line[n] != '\0' && line[n] != ' ')
			n++;
		while (line[n] != '\0' && line[n] == ' ')
			n++;
	}
	lenght = get_lenght(line, n);
	i = 0;
	word = (char *)malloc(lenght * sizeof(char *));
	while (line[n] != '\0' && line[n] != ' ')
	{
		word[i] = line[n];
		i++;
		n++;
	}
	word[i] = '\0';
	return (word);
}

int	check_all_ids(t_global *global)
{
	int	n;

	n = 0;
	if (global->parse->NO == 1)
		n++;
	if (global->parse->SO == 1)
		n++;
	if (global->parse->WE == 1)
		n++;
	if (global->parse->EA == 1)
		n++;
	if (global->parse->F == 1)
		n++;
	if (global->parse->C == 1)
		n++;
	if (n == 6)
		return (1);
	return (0);
}

int	has_cub_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}

void save_paths(char *line, char *word, t_global *global)
{
	if (ft_strcmp(word, "NO") == 0)
	{
		global->parse->NO = 1;
		global->path->NO = get_word(line, 2);
	}
	else if (ft_strcmp(word, "SO") == 0)
	{
		global->parse->SO = 1;
		global->path->SO = get_word(line, 2);
	}
	else if (ft_strcmp(word, "WE") == 0)
	{
		global->parse->WE = 1;
		global->path->WE = get_word(line, 2);
	}
	else if (ft_strcmp(word, "EA") == 0)
	{
		global->parse->EA = 1;
		global->path->EA = get_word(line, 2);
	}
}
