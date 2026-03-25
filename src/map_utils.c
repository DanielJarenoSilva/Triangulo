/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:58:38 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/25 12:53:42 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_map_line(t_global *global, int *char_flag, int n, int m)
{
    if (global->map->map[n][m] != '0' && global->map->map[n][m] != '1' && global->map->map[n][m] != ' ')
    {
        if (global->map->map[n][m] == 'N' || global->map->map[n][m] == 'S' || global->map->map[n][m] == 'E' || global->map->map[n][m] == 'W')
        {
            if (!*char_flag)
                *char_flag = 1;
            else
                return (print_errors_1(9), 0);
        }
        else
            return (print_errors_1(10), 0);
    }
    return (1);
}
