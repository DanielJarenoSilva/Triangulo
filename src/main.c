/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:54:26 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/07 17:13:43 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3D.h"


char	**create_map(void)
{
	char	**map;

	map = malloc(6 * sizeof(char *));
	map[0] = ft_strdup("11111");
	map[1] = ft_strdup("10001");
	map[2] = ft_strdup("10001");
	map[3] = ft_strdup("10001");
	map[4] = ft_strdup("100N1");
	map[5] = ft_strdup("11111");
	return (map);
}

int	main(void)
{
	t_map map;

	map.map = create_map();
	map.height = 6;
	map.width = 5;
	cube(&map);
	return (0);
}
