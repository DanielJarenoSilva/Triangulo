/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 12:54:26 by lvargas-          #+#    #+#             */
/*   Updated: 2026/02/25 13:37:20 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "cub3D.h"

int main(int argc, char *argv[])
{
    char *file_name;
    int fd;

    if (argc != 2)
		return (print_errors_1(1), 1);
    file_name = argv[1];
    fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (close(fd), print_errors_1(2), 1);
    check_errors_1(file_name);
    close(fd);
    return (0);
}
