/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djareno <djareno@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:48:42 by djareno           #+#    #+#             */
/*   Updated: 2026/03/10 12:13:23 by djareno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	put_pixel(mlx_image_t *img, int x, int y, uint32_t color)
{
	uint8_t	*pixel;

	pixel = (uint8_t *)&img->pixels[(y * img->width + x) * 4];
	*(uint32_t *)pixel = color;
}
