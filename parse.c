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

int		det_arg(char *line, t_map *map)
{
	char	**tab;
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(tab = ft_split_whitespaces(line)))
		return (0);
	if (!tab || !tab[0])
		return (1);
	if (ft_charset(tab[0], "012NESW"))
		return (add_map(tab, map))
	if (tab[0] == "R")
		return (!add_r(tab, map))
	if (tab[0] == "NO")
		return (!add_no(tab, map))
	if (tab[0] == "SO")
		return (!add_so(tab, map))
	if (tab[0] == "WE")
		return (!add_we(tab, map))
	if (tab[0] == "EA")
		return (!add_ea(tab, map))
	if (tab[0] == "S")
		return (!add_s(tab, map))
	if (tab[0] == "F")
		return (!add_f(tab, map))
	if (tab[0] == "C")
		return (!add_c(tab, map))
	return (0);
}

int		parse(char *arg, t_map *map)
{
	int		fd;
	int 	ret;
	char	*line;
	t_map	map;

	fd = open(arg, "O_RDONLY");
	while ((ret = get_next_line(fd, &line)) > 0)
		if (!det_arg(line, map))
			return (-1);
	return ((ret == -1) ? -1 : 1);
}