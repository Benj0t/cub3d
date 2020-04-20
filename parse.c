/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 17:42:53 by bemoreau          #+#    #+#             */
/*   Updated: 2020/02/24 16:02:54 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_charset(char *str, char *tof)
{
	int i;
	int y;

	i = 0;
	while (str[i])
	{
		y = 0;
		while (tof[y] && str[i] != tof[y])
			y++;
		if (str[i] == tof[y])
			return (1);
		i++;
	}
}
// 0 = Wrong Map
// -1 = Wrong Key
// -2 = Wrong Path
// -3 = Missing smthg
int		det_arg(char *line, t_map *map)
{
	char	**tab;
	static int bool = 0;

	if (!(tab = ft_split(line)))
		return (0);
	if (!tab || !tab[0])
		return (1);
	if (bool)
		return(add_map(tab, &map));
	if (ft_charset(tab[0], "012NESW" && bool == 0))
	{
		bool = 1;
		return (add_map(tab, &map));
	}
	if (tab[0] == "R")
		return (!add_r(tab, &map))
	if (tab[0] == "NO")
		return (!add_path(tab, &(map.no)))
	if (tab[0] == "SO")
		return (!add_path(tab, &(map.so)))
	if (tab[0] == "WE")
		return (!add_path(tab, &(map.we)))
	if (tab[0] == "EA")
		return (!add_path(tab, &(map.est)))
	if (tab[0] == "S")
		return (!add_path(tab, &(map.spr)))
	if (tab[0] == "F")
		return (!add_comp(tab, &(map->fl_r), &(map->fl_r), &(map->fl_r));
	if (tab[0] == "C")
		return (!add_comp(tab, &(map->cl_r), &(map->cl_r), &(map->cl_r));
	return (0);
}

int		parse(char *arg, t_map *map)
{
	int		fd;
	int 	ret;
	char	*line;
	t_map	map;

	fd = open(arg, O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!det_arg(line, map))
			return (-1);
		free(line);
	}
	return ((ret == -1) ? -1 : 1);
}