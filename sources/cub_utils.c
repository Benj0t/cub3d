#include "cub3d.h"

int is_bin(int nb)
{
	if (nb == 0 || nb == 1)
		return (1);
	return (0);
}

int is_rgb(int nb)
{
	if (0 <= nb && nb <= 255)
		return (1);
	return (0);
}

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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