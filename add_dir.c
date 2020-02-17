#include "cub3d.h"

int		add_r(char **tab, t_map *map)
{
	int x;
	int y;

	x = 1;
	while (tab[x])
	{
		y = 0;
		if (x == 3)
			return (0);
		while (tab[x][y])
		{
			if (!is_digit(tab[x][y++]))
				return (0);
		}
		map->resol[x = 1] = tab[x];
	}
}