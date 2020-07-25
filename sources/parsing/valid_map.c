/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:53 by bemoreau          #+#    #+#             */
/*   Updated: 2020/07/25 13:08:53 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hor_check(char **tab, t_w_check *wall, int y, int x)
{
	int i;

	i = y;
	while (tab[i])
	{
		if (tab[i++][x] == '1')
			wall->s = 1;
	}
	i = y;
	while (i >= 0)
	{
		if (tab[i--][x] == '1')
			wall->n = 1;
	}
}

void	ver_check(char **tab, t_w_check *wall, int y, int x)
{
	int i;

	i = x;
	while (tab[y][i])
	{
		if (tab[y][i++] == '1')
			wall->e = 1;
	}
	i = x;
	while (i >= 0)
	{
		if (tab[y][i--] == '1')
			wall->o = 1;
	}
}

int	 verif_pos(char **tab, int y, int x)
{
	int i;
	int j;
	t_w_check wall;

	i = y;
	j = x;
	wall = init_w_check();
	ver_check(tab, &wall, y, x);
	hor_check(tab, &wall, y, x);
	if (!wall.n || !wall.s || !wall.o || !wall.e)
		return (1);
	return (0);
}

int	 map_closed(t_pmlx *pmlx, int y, int x)
{
	if (y < 0 || x < 0 || x > pmlx->s.tabHeight || y > ft_strlen(pmlx->s.cmap))
		return (0);
	if (find_char("O1S", pmlx->s.cmap[x][y]))
		return (1);
	if (pmlx->s.cmap[x][y] == '0')
		pmlx->s.cmap[x][y] = 'O';
	else if (pmlx->s.cmap[x][y] == '2')
	{
		lst_add_front(pmlx->s.list, ft_lstnew(y, x));
		pmlx->s.cmap[x][y] = 'S';
	}
	map_closed(pmlx, y + 1, x);
	map_closed(pmlx, y, x + 1);
	map_closed(pmlx, y - 1, x);
	map_closed(pmlx, y, x - 1);
}

int	 auth_char(t_pmlx *pmlx)
{
	int i;
	int j;
	char *str;

	str = "012NSEWO ";
	i = 0;
	j = 0;
	while (pmlx->s.cmap[j])
	{
		while (pmlx->s.cmap[j][i])
		{
			if (!find_char(str, pmlx->s.cmap[j][i]))
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	 valid_map(t_pmlx *pmlx)
{
	int ret;

	ret = auth_char(pmlx);
	ft_putstr("auth OK\n");
	if (!ret)
		ret = map_closed(pmlx);
	ft_putstr("valid_map OK\n");
	return (ret);
}