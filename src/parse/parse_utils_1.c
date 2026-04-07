/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:53:52 by lvargas-          #+#    #+#             */
/*   Updated: 2026/04/07 19:51:56 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

int	advance_word(char *line, int n)
{
	while (line[n] != '\0' && line[n] != ' ')
		n++;
	while (line[n] != '\0' && line[n] == ' ')
		n++;
	return (n);
}

char	*return_word(char *line, int n)
{
	int		i;
	char	*word;

	i = 0;
	if (line[n] != '\0' && line[n] != ' ' && line[n] != '\n')
	{
		word = (char *)malloc((get_lenght(line, n) * sizeof(char)) + 1);
		while (line[n] != '\0' && line[n] != ' ' && line[n] != '\n')
		{
			word[i] = line[n];
			i++;
			n++;
		}
		word[i] = '\0';
	}
	else
	{
		word = NULL;
	}
	return (word);
}

char	*get_word(char *line, int nb)
{
	char	*word;
	int		n;

	n = 0;
	while (line[n] == ' ')
		n++;
	if (line[n] != '\0' && nb == 2)
		n = advance_word(line, n);
	else if (line[n] != '\0' && nb == 3)
	{
		n = advance_word(line, n);
		n = advance_word(line, n);
	}
	word = return_word(line, n);
	return (word);
}

int	check_all_ids(t_global *global)
{
	int	n;

	n = 0;
	if (global->parse->no == 1)
		n++;
	if (global->parse->so == 1)
		n++;
	if (global->parse->we == 1)
		n++;
	if (global->parse->ea == 1)
		n++;
	if (global->parse->f == 1)
		n++;
	if (global->parse->c == 1)
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
