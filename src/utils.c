/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:43:19 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/09 20:23:16 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int get_lenght(char *line, int n)
{
    int lenght;

    lenght = 0;
    while (line[n] != '\0' && line[n] != ' ')
    {
        lenght++;
        n++;
    }
    return (lenght);
}

char *get_word(char *line, int nb)
{
    char *word;
    int i;
    int lenght;
    int n;

    n = 0;
    while (line[n] == ' ')
        n++;
    if (line[n] != '\0' && nb == 2)
    {
        while (line[n] != '\0' && line[n] != ' ')
            n++;
        while (line[n] != '\0' && line[n] == ' ')
            n++;
    }
    lenght = get_lenght(line, n);
    i = 0;
    word = (char *)malloc(lenght * sizeof(char *));
    while (line[n] != '\0' && line[n] != ' ')
    {
        word[i] = line[n];
        i++;
        n++;
    }
    word[i] = '\0';
    return (word);
}

int check_all_ids(t_parse *parse)
{
    int n;

    n = 0;
    if (parse->NO == 1)
        n++;
    if (parse->SO == 1)
        n++;
    if (parse->WE == 1)
        n++;
    if (parse->EA == 1)
        n++;
    if (parse->F == 1)
        n++;
    if (parse->C == 1)
        n++;

    if (n == 6)
        return (1);
    return (0);
}
