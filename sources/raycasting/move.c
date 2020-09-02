/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:59:01 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/02 18:27:04 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mv_right(t_pmlx *pmlx)
{
	if (pmlx->s.map[(int)(pmlx->pl.posX + pmlx->pl.planeX * pmlx->pl.moveSpeed)]\
		[(int)pmlx->pl.posY] == 0)
		pmlx->pl.posX += pmlx->pl.planeX * pmlx->pl.moveSpeed;
	if (pmlx->s.map[(int)pmlx->pl.posX]\
		[(int)(pmlx->pl.posY + pmlx->pl.planeY * pmlx->pl.moveSpeed)] == 0)
		pmlx->pl.posY += pmlx->pl.planeY * pmlx->pl.moveSpeed;
}

void	mv_left(t_pmlx *pmlx)
{
	if (pmlx->s.map[(int)(pmlx->pl.posX - pmlx->pl.planeX * pmlx->pl.moveSpeed)]\
		[(int)pmlx->pl.posY] == 0)
		pmlx->pl.posX -= pmlx->pl.planeX * pmlx->pl.moveSpeed;
	if (pmlx->s.map[(int)pmlx->pl.posX]\
		[(int)(pmlx->pl.posY - pmlx->pl.planeY * pmlx->pl.moveSpeed)] == 0)
		pmlx->pl.posY -= pmlx->pl.planeY * pmlx->pl.moveSpeed;
}

void	forward(t_pmlx *pmlx)
{
	if (pmlx->s.map[(int)(pmlx->pl.posX + pmlx->pl.dirX * pmlx->pl.moveSpeed)]\
		[(int)pmlx->pl.posY] == 0)
		pmlx->pl.posX += pmlx->pl.dirX * pmlx->pl.moveSpeed;
	if (pmlx->s.map[(int)pmlx->pl.posX]\
		[(int)(pmlx->pl.posY + pmlx->pl.dirY * pmlx->pl.moveSpeed)] == 0)
		pmlx->pl.posY += pmlx->pl.dirY * pmlx->pl.moveSpeed;
}

void	downward(t_pmlx *pmlx)
{
	if (pmlx->s.map[(int)(pmlx->pl.posX - pmlx->pl.dirX * pmlx->pl.moveSpeed)]\
		[(int)pmlx->pl.posY] == 0)
		pmlx->pl.posX -= pmlx->pl.dirX * pmlx->pl.moveSpeed;
	if (pmlx->s.map[(int)pmlx->pl.posX]\
		[(int)(pmlx->pl.posY - pmlx->pl.dirY * pmlx->pl.moveSpeed)] == 0)
		pmlx->pl.posY -= pmlx->pl.dirY * pmlx->pl.moveSpeed;
}

void	rot_left(t_pmlx *pmlx)
{
	pmlx->pl.oldDirX = pmlx->pl.dirX;
	pmlx->pl.dirX = pmlx->pl.dirX * cos(pmlx->pl.rotSpeed) -\
					pmlx->pl.dirY * sin(pmlx->pl.rotSpeed);
	pmlx->pl.dirY = pmlx->pl.oldDirX * sin(pmlx->pl.rotSpeed) +\
					pmlx->pl.dirY * cos(pmlx->pl.rotSpeed);
	pmlx->pl.oldPlaneX = pmlx->pl.planeX;
	pmlx->pl.planeX = pmlx->pl.planeX * cos(pmlx->pl.rotSpeed) -\
					pmlx->pl.planeY * sin(pmlx->pl.rotSpeed);
	pmlx->pl.planeY = pmlx->pl.oldPlaneX * sin(pmlx->pl.rotSpeed) +\
					pmlx->pl.planeY * cos(pmlx->pl.rotSpeed);
}

void	rot_right(t_pmlx *pmlx)
{
	pmlx->pl.oldDirX = pmlx->pl.dirX;
	pmlx->pl.dirX = pmlx->pl.dirX * cos(-pmlx->pl.rotSpeed) -\
					pmlx->pl.dirY * sin(-pmlx->pl.rotSpeed);
	pmlx->pl.dirY = pmlx->pl.oldDirX * sin(-pmlx->pl.rotSpeed) +\
					pmlx->pl.dirY * cos(-pmlx->pl.rotSpeed);
	pmlx->pl.oldPlaneX = pmlx->pl.planeX;
	pmlx->pl.planeX = pmlx->pl.planeX * cos(-pmlx->pl.rotSpeed) -\
					pmlx->pl.planeY * sin(-pmlx->pl.rotSpeed);
	pmlx->pl.planeY = pmlx->pl.oldPlaneX * sin(-pmlx->pl.rotSpeed) +\
					pmlx->pl.planeY * cos(-pmlx->pl.rotSpeed);
}
