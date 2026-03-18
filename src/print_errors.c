/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:08:39 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/18 19:36:54 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3D.h"

void	print_errors_1(int error)
{
	char	*error_msg;

	error_msg = "\0";
	if (error == 1)
		error_msg = "Error\nDebes introducir como único argumento el nombre del mapa.\n";
	else if (error == 2)
		error_msg = "Error\nArchivo no encontrado.\n";
	else if (error == 3)
		error_msg = "Error\nExtensión no válida.\n";
	else if (error == 4)
		error_msg = "Error\nFalta uno o más identificadores.\n";
	else if (error == 5)
		error_msg = "Error\nFormato de identificadores erróneo.\n";
	else if (error == 6)
		error_msg = "Error\nColores RGB fuera de rango.\n";
	else if (error == 7)
		error_msg = "Error\nIdentificador no válido.\n";
	else if (error == 8)
		error_msg = "Error\nEl mapa debe estar rodeado de paredes.\n";
	else if (error == 9)
		error_msg = "Error\nNo puede haber más de un personaje.\n";
	else if (error == 10)
		error_msg = "Error\nComponentes del mapa erróneos.\n";
	if (error_msg)
		write(1, error_msg, ft_strlen(error_msg));
}

void	print_errors_2(int error)
{
	char	*error_msg;

	error_msg = "\0";
	if (error == 1)
		error_msg = "Error\nMás de un identificador del mismo tipo.\n";
	else if (error == 2)
		error_msg = "Error\nFalta ruta de identificador.\n";
	else if (error == 3)
		error_msg = "Error\nLa ruta de una o más texturas no existe.\n";
	else if (error == 4)
		error_msg = "Error\nNo se ha establecido la posición del personaje.\n";
	write(1, error_msg, ft_strlen(error_msg));
}
