/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 14:58:38 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/18 15:07:36 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_map_line(t_global *global, int *char_flag, int n, int m)
{
    if (global->map[n][m] != '0' && global->map[n][m] != '1' && global->map[n][m] != ' ')
    {
        if (global->map[n][m] == 'N' || global->map[n][m] == 'S' || global->map[n][m] == 'E' || global->map[n][m] == 'W')
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
