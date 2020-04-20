/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 16:58:01 by bemoreau          #+#    #+#             */
/*   Updated: 2020/02/21 18:39:04 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		add_r(char **tab, t_map *map)
{
	int x;
	int y;

	if (map->win_x || map->win_y)
		return (0);
	x = 0;
	while (tab[++x])
	{
		y = 0;
		if (x >= 3)
			return (0);
		while (tab[x][y])
			if (tab[x][y] && !is_digit(tab[x][y++]))
				return (0);
		map->x = (x == 1) ? ft_atoi(tab[x]) : map->x;
		map->y = (x == 2) ? ft_atoi(tab[x]) : map->y;
	}
	if (map->x <= 0 || map->y <= 0 || x == 3)
		return (0);
	return (1);
}

int		add_path(char **tab, char *var[1])
{
	int x;
	int fd;

	x = 0;
	while (tab[++x])
	{
		if (x >= 3)
			return (0);
		if (fd = open(tab[x], O_RDONLY) == -1)
		{
			close(fd);
			return(0);
		}
		var[0] = ft_strdup(tab[x]);
	}
	return((x == 2) ? 1 : 0);
}

int		is_rgb(int nb)
{
	return ((nb >= 0 && nb <= 255) ? nb : -1);
}

int		add_rgb(char **tab, int *r, int *g, int *b)
{
	int x;
	int y;

	if (*r || *g || *b)
		return (0);
	x = 0;
	while (tab[++x])
	{
		y = 0;
		if (x >= 4)
			return (0);
		while (tab[x][y])
			if (tab[x][y] && !is_digit(tab[x][y++]))
				return (0);
		*r = is_rgb((x == 1) ? ft_atoi(tab[x]) : *r);
		*g = is_rgb((x == 2) ? ft_atoi(tab[x]) : *g);
		*b = is_rgb((x == 3) ? ft_atoi(tab[x]) : *b);
	}
	if (*r == -1 || *g == -1 || *b == -1 || x >= 3)
		return (0);
	return (1);
}