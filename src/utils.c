/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:43:19 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/12 13:11:42 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

int	get_lenght(char *line, int n)
{
	int	lenght;

	lenght = 0;
	while (line[n] != '\0' && line[n] != ' ' && line[n] != '\n')
	{
		lenght++;
		n++;
	}
	return (lenght);
}
