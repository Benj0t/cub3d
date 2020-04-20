/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:15:02 by bemoreau          #+#    #+#             */
/*   Updated: 2020/02/21 16:56:08 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			*init_tab(unsigned int len)
{
	char **tab;

	if (!(tab = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	tab[len] = NULL;
	return(tab);
}
static t_map	init_map(t_map map)
{
	map->fl_r = 0;
	map->fl_g = 0;
	map->fl_b = 0;
	map->cl_r = 0;
	map->cl_g = 0;
	map->cl_b = 0;
	map->win_x = 0;
	map->win_y = 0;
	map->grid = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->est = NULL;
	map->spr = NULL;
	map->fl = NULL;
	map->ceil = NULL;
	return(map);
}


int				main(int argc, char **argv)
{
	t_map map;

	init_map(&map);
	if (argc == 1)
		parse(argv[0], &map);
}