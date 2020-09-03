/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:03:43 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/03 16:24:59 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sp_rgb(t_pmlx *pmlx, t_color color, int stripe, int y)
{
	pmlx->mlx.data_addr[(y * pmlx->s.r.x + stripe) * 4 + RED_COMP] = color.r;
	pmlx->mlx.data_addr[(y * pmlx->s.r.x + stripe) * 4 + GREEN_COMP] = color.g;
	pmlx->mlx.data_addr[(y * pmlx->s.r.x + stripe) * 4 + BLUE_COMP] = color.b;
}

void	store_rgb(t_color *c, int nb, int index)
{
	if (index == 1)
		c->r = nb;
	if (index == 2)
		c->g = nb;
	if (index == 3)
		c->b = nb;
}

void	put_rgb(t_color *c, char **tab)
{
	int i;
	int j;
	int nb;

	i = 0;
	j = 0;
	nb = 0;
	while (++j != 4)
	{
		while (tab[1][i] && tab[1][i] != ',' && tab[1][i] != '\n')
		{
			if (tab[1][i] >= '0' && tab[1][i] <= '9')
				nb = nb * 10 + tab[1][i] - '0';
			i++;
		}
		i++;
		store_rgb(c, nb, j);
		nb = 0;
	}
}

int		tab_is_rgb(char **tab)
{
	int i;
	int j;
	int nb;

	i = 0;
	j = 0;
	nb = 0;
	while (j++ < 3)
	{
		while (tab[1][i] && tab[1][i] != ',' && tab[1][i + 1] != '\n')
		{
			if (tab[1][i] >= '0' && tab[1][i] <= '9')
				nb = nb * 10 + tab[1][i] - 48;
			else
				return (0);
			i++;
		}
		i++;
		if (nb < 0 || nb > 255)
			return (0);
		nb = 0;
	}
	return (1);
}
