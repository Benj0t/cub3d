/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 13:08:28 by bemoreau          #+#    #+#             */
/*   Updated: 2020/07/25 13:24:24 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pos_north(t_pmlx *pmlx)
{
	pmlx->pl.posX = -1;
	pmlx->pl.posY = 0;
	pmlx->pl.dirX = 0;
	pmlx->pl.dirY = 0.66;
}

void	pos_east(t_pmlx *pmlx)
{
	pmlx->pl.posX = 0;
	pmlx->pl.posY = 1;
	pmlx->pl.dirX = 0.66;
	pmlx->pl.dirY = 0;
}

void	pos_south(t_pmlx *pmlx)
{
	pmlx->pl.posX = 1;
	pmlx->pl.posY = 0;
	pmlx->pl.dirX = 0;
	pmlx->pl.dirY = -0.66;
}

void	pos_west(t_pmlx *pmlx)
{
	pmlx->pl.posX = 0;
	pmlx->pl.posY = -1;
	pmlx->pl.dirX = 0;
	pmlx->pl.dirY = -0.66;
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