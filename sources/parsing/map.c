/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:20 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/27 16:06:57 by bemoreau         ###   ########.fr       */
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
	if (y < 0 || x < 0 || x > pmlx->s.tabHeight ||\
		y >= ft_strlen(pmlx->s.cmap[x]))
		ft_puterr("Map invalid", pmlx);
	if (find_char("O1S", pmlx->s.cmap[x][y]))
		return (1);
	if (pmlx->s.cmap[x][y] == '\0' || pmlx->s.cmap[x][y] == ' ')
		ft_puterr("Map invalid", pmlx);
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
	pmlx->s.tabHeight = tab_len(pmlx->s.cmap);
	if (!(pmlx->s.map = (int **)malloc(sizeof(int *) * (\
		pmlx->s.tabHeight + 1))))
		return (0);
	pmlx->s.map[pmlx->s.tabHeight] = NULL;
	while (i < pmlx->s.tabHeight)
	{
		j = -1;
		len = ft_strlen(pmlx->s.cmap[i]);
		if (!(pmlx->s.map[i] = (int *)malloc(sizeof(int) * (len + 1))))
			return (0);
		pmlx->s.map[i][len] = '\0';
		while (++j < len)
			if ((pmlx->s.map[i][j] = get_char(pmlx->s.cmap[i][j])) == -1)
				ft_puterr("Unauthorized character", pmlx);
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
		return (0);
	pmlx->s.cmap[n] = NULL;
	while (j < n)
	{
		start = ++i;
		while (pmlx->s.map_join[i] != '\n' || pmlx->s.map_join[i] == '\r')
			i++;
		len = i - start;
		pmlx->s.cmap[j++] = ft_substr(pmlx->s.map_join, start, len);
	}
	return (1);
}
