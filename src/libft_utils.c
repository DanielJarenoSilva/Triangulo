/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvargas- <lvargas-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 13:25:10 by lvargas-          #+#    #+#             */
/*   Updated: 2026/03/17 21:33:21 by lvargas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (2048);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	n;
	int	negative;

	negative = 0;
	n = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			negative = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		n += *nptr - '0';
		if (ft_isdigit(*(nptr + 1)))
			n = n * 10;
		nptr++;
	}
	if (negative == 1)
		n *= -1;
	return (n);
}

char	*ft_strncpy(char *dest, const char *src, int n)
{
    int	i;

    i = 0;
    while (i < n && src[i] && src[i] != '\n')
    {
        dest[i] = src[i];
        i++;
    }
    while (i < n)
    {
        dest[i] = ' ';
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
