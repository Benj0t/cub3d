/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:28 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/03 16:30:29 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pos_north(t_pmlx *pmlx)
{
	pmlx->pl.posx = -1;
	pmlx->pl.posy = 0;
	pmlx->pl.dirx = 0;
	pmlx->pl.diry = 0.66;
}

void	pos_east(t_pmlx *pmlx)
{
	pmlx->pl.posx = 0;
	pmlx->pl.posy = 1;
	pmlx->pl.dirx = 0.66;
	pmlx->pl.diry = 0;
}

void	pos_south(t_pmlx *pmlx)
{
	pmlx->pl.posx = 1;
	pmlx->pl.posy = 0;
	pmlx->pl.dirx = 0;
	pmlx->pl.diry = -0.66;
}

void	pos_west(t_pmlx *pmlx)
{
	pmlx->pl.posx = 0;
	pmlx->pl.posy = -1;
	pmlx->pl.dirx = 0;
	pmlx->pl.diry = -0.66;
}

void	pos_dealer(t_pmlx *pmlx, char c)
{
	if (c == 'N')
		pos_north(pmlx);
	if (c == 'E')
		pos_east(pmlx);
	if (c == 'S')
		pos_south(pmlx);
	if (c == 'W')
		pos_west(pmlx);
}
