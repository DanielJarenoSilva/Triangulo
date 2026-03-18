/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 13:39:37 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/18 19:37:06 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "get_next_line.h"

int	check_middle_walls(t_global *global, int n)
{
    int m;
    
    m = 0;
    while (m < global->map_width)
    {
        if (global->map[n][m] == '0' && (global->map[n][m - 1] == ' ' || m == 0))
            return (print_errors_1(8), 0);
        else if (global->map[n][m] == '0' && (global->map[n][m + 1] == ' ' || m == (global->map_width - 1)))
            return (print_errors_1(8), 0);
        m++;
    }
    return (1);
}

int	has_walls(t_global *global)
{
	int		n;
    int m;

    n = 0;
	while (n < global->map_height)
	{
		if (n == 0 || n == (global->map_height - 1))
		{
            m = 0;
            while (m < global->map_width)
            {
                if (global->map[n][m] != '1' && global->map[n][m] != ' ')
                    return (print_errors_1(8), 0);
                m++;
            }
        }
        else
        {
            if (check_middle_walls(global, n) == 0)
                return (0);
        }
		n++;
	}
	return (1);
}

int is_surrounded_by_walls(t_global *global)
{
    int n;
    int m;

    n = 0;
    while (n < global->map_height)
    {
        m = 0;
        while (m < global->map_width)
        {
            if (global->map[n][m] == '0')
            {
                if (global->map[n - 1][m] == ' ' || global->map[n + 1][m] == ' ')
                    return (print_errors_1(8), 0);
            }
            m++;
        }
        n++;
    }
    return (1);
}

int check_map_components(t_global *global)
{
    int n;
    int m;
    int char_flag;

    n = 0;
    char_flag = 0;
    while (n < global->map_height)
    {
        m = 0;
        while (m < global->map_width)
        {
            if (check_map_line(global, &char_flag, n, m) == 0)
                return (0);
            m++;
        }
        n++;
    }
    if (!char_flag)
        return (print_errors_2(4), 0);
    return (1);
}

int check_map(t_global *global)
{
    if (check_map_components(global) == 0)
        return (-1);
    if (has_walls(global) == 0)
        return (-1);
    if (is_surrounded_by_walls(global) == 0)
        return (-1);
    return (0);
}
