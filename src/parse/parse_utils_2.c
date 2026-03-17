/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 17:46:04 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/17 17:55:53 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_color_format(char *colors)
{
	int i;
	int coma_count;
	int color_count;

	coma_count = 0;
	color_count = 0;
	i = 0;
	while (colors[i])
	{
		if (!ft_isdigit(colors[i]) && colors[i] != ',')
			return (print_errors_1(5), -1);
		if ((ft_isdigit(colors[i]) && i == 0) || (ft_isdigit(colors[i]) && !ft_isdigit(colors[i - 1])))
			color_count++;
		if (colors[i] == ',')
			coma_count++;
		i++;
	}
	if (coma_count != 2 || color_count != 3)
		return (print_errors_1(5), -1);
	return (0);
}

int get_nb_len(char *colors, int i)
{
	int len;

	len = 0;
	while (colors[i] != '\0' && colors[i] != ',')
	{
		len++;
		i++;	
	}
	return (len);
}

int check_color_range(int n)
{
	if (n < 0 || n > 255)
		return (print_errors_1(6), -1);
	return (0);
}

char *fill_color(char *colors, int i)
{
	char *nb;
	int j;
	
	nb = (char *)malloc((get_nb_len(colors, i) + 1) * sizeof(char));
	j = 0;
	while (colors[i] != '\0' && colors[i] != ',')
	{
		nb[j] = colors[i];
		j++;
		i++;
	}
	nb[j] = '\0';
	return (nb);
}

int get_color(char *colors, int n)
{
	int i;
	char *nb;
	int number;
	
	if (check_color_format(colors) == -1)
		return (-1);
	i = 0;
	while (n != 1)
	{
		if (colors[i] == ',')
			n--;
		i++;
	}
	nb = fill_color(colors, i);
	number = ft_atoi(nb);
	if (check_color_range(number) == -1)
		return (free(nb), -1);
	return (free(nb), number);
}
