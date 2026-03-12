/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:08:39 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/12 13:01:10 by lvargas-         ###   ########.fr       */
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
	else if (error == 3)
		error_msg = "Error\nExtensión no válida.\n";
	else if (error == 4)
		error_msg = "Error\nFalta uno o más identificadores.\n";
	else if (error == 5)
		error_msg = "Error\nFormato de mapa erróneo.\n";
	if (error_msg)
		write(1, error_msg, ft_strlen(error_msg));
}
