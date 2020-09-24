/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:20 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/20 16:11:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		count_n(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i])
		if (str[i++] == '\n')
			n++;
	return (n);
}

int				map_closed(t_pmlx *pmlx, int y, int x)
{
	if (y < 0 || x < 0 || x > pmlx->s.tabheight ||\
		y >= ft_strlen(pmlx->s.cmap[x]))
		ft_puterr("Error\nMap", pmlx, 1);
	if (find_char("O1S", pmlx->s.cmap[x][y]))
		return (1);
	if (pmlx->s.cmap[x][y] == '\0' || pmlx->s.cmap[x][y] == ' ')
		ft_puterr("Error\nMap", pmlx, 1);
	if (pmlx->s.cmap[x][y] == '0')
		pmlx->s.cmap[x][y] = 'O';
	else if (pmlx->s.cmap[x][y] == '2')
	{
		pmlx->s.sprite_num++;
		pmlx->s.cmap[x][y] = 'S';
	}
	map_closed(pmlx, y + 1, x);
	map_closed(pmlx, y, x + 1);
	map_closed(pmlx, y - 1, x);
	map_closed(pmlx, y, x - 1);
	return (1);
}

int				convert_map(t_pmlx *pmlx)
{
	int len;
	int i;
	int j;

	i = 0;
	pmlx->s.tabheight = tab_len(pmlx->s.cmap);
	if (!(pmlx->s.map = (int **)malloc(sizeof(int *) * (\
		pmlx->s.tabheight + 1))))
		ft_puterr("Error\n(malloc)", pmlx, 1);
	pmlx->s.map[pmlx->s.tabheight] = NULL;
	while (i < pmlx->s.tabheight)
	{
		j = -1;
		len = ft_strlen(pmlx->s.cmap[i]);
		if (!(pmlx->s.map[i] = (int *)malloc(sizeof(int) * (len + 1))))
			ft_puterr("Error\n(malloc)", pmlx, 1);
		pmlx->s.map[i][len] = '\0';
		while (++j < len)
			if ((pmlx->s.map[i][j] = get_char(pmlx->s.cmap[i][j])) == -1)
				ft_puterr("Error\nWrong character", pmlx, 1);
		i++;
	}
	return (1);
}

int				create_map(t_pmlx *pmlx)
{
	int n;
	int i;
	int j;
	int start;
	int len;

	i = -1;
	j = 0;
	start = 0;
	n = count_n(pmlx->s.map_join);
	if (!(pmlx->s.cmap = (char **)malloc(sizeof(char *) * (n + 1))))
		ft_puterr("Error\n(malloc)", pmlx, 1);
	pmlx->s.cmap[n] = NULL;
	while (j < n)
	{
		start = ++i;
		while (pmlx->s.map_join[i] != '\n' || pmlx->s.map_join[i] == '\r')
			i++;
		len = i - start;
		if (!(pmlx->s.cmap[j++] = ft_substr(pmlx->s.map_join, start, len)))
			ft_puterr("Error\n(malloc)", pmlx, 1);
	}
	return (1);
}
