/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:54:26 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/04 12:38:06 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3D.h"


char	**create_map(void)
{
	char	**map;
	int		x;

	x = 0;
	map = malloc(4 * sizeof(char *));
	map[0] = ft_strdup("11111");
	map[1] = ft_strdup("10001");
	map[2] = ft_strdup("100N1");
	map[3] = ft_strdup("11111");
	return (map);
}

int	main(void)
{
	t_map map;

	map.map = create_map();
	map.height = 4;
	map.width = 5;
	cube(&map);
	return (0);
}
