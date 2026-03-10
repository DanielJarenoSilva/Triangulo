/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:54:26 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/10 13:10:43 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3D.h"

char	**create_map(void)
{
	char	**map;

	map = malloc(6 * sizeof(char *));
	map[0] = ft_strdup("111111");
	map[1] = ft_strdup("100001");
	map[2] = ft_strdup("101101");
	map[3] = ft_strdup("101001");
	map[4] = ft_strdup("101N01");
	map[5] = ft_strdup("111111");
	return (map);
}

int	main(void)
{
	t_map	map;

	map.map = create_map();
	map.height = 6;
	map.width = 6;
	cube(&map);
	return (0);
}
