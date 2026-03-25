/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 13:40:58 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/25 12:53:42 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(char **map)
{
    int	i;

    if (!map)
        return ;
    i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}


void free_struct(t_global *global)
{
    if (!global)
        return ;
    if (global->map->map)
        free_map(global->map->map);
    if (global->path)
    {
        free(global->path->NO);
        free(global->path->SO);
        free(global->path->WE);
        free(global->path->EA);
        free(global->path);
    }
    free(global->parse);
    free(global);
}
