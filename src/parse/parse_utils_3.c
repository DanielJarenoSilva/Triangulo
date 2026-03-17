/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:56:35 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/17 17:57:04 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
