/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:08:39 by lvargas-          #+#    #+#             */
/*   Updated: 2026/02/25 13:18:10 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3D.h"

void	print_errors_1(int error)
{
	char	*error_msg;

	error_msg = "\0";
	if (error == 1)
		error_msg = "Error\nDebes introducir solamente el nombre del archivo.\n";
	else if (error == 2)
		error_msg = "Error\nArchivo no encontrado.\n";
	if (error == 3)
		error_msg = "Error\nExtensión no válida.\n";
	if (error_msg)
		write(1, error_msg, ft_strlen(error_msg));
}
