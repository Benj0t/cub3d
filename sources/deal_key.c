/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/25 18:49:55 by bemoreau          #+#    #+#             */
/*   Updated: 2020/06/25 19:17:33 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map[mapWidth][mapHeight]={
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};


int		deal_key(int key, t_pmlx *pmlx)
{
	printf("%d\n", key);
	if (key == W_KEY_L)//W
	{
		if(map[(int)(pmlx->pl.posX + pmlx->pl.dirX * pmlx->pl.moveSpeed)][(int)pmlx->pl.posY] == 0)
		{
			pmlx->pl.posX += pmlx->pl.dirX * pmlx->pl.moveSpeed;
		}
		if(map[(int)pmlx->pl.posX][(int)(pmlx->pl.posY + pmlx->pl.dirY * pmlx->pl.moveSpeed)] == 0)
			pmlx->pl.posY += pmlx->pl.dirY * pmlx->pl.moveSpeed;
	}
	if (key == S_KEY_L)//S
	{
		if(map[(int)(pmlx->pl.posX - pmlx->pl.dirX * pmlx->pl.moveSpeed)][(int)pmlx->pl.posY] == 0)
			pmlx->pl.posX -= pmlx->pl.dirX * pmlx->pl.moveSpeed;
		if(map[(int)pmlx->pl.posX][(int)(pmlx->pl.posY - pmlx->pl.dirY * pmlx->pl.moveSpeed)] == 0)
			pmlx->pl.posY -= pmlx->pl.dirY * pmlx->pl.moveSpeed;
	}
	if (key == A_KEY_L)//A
	{
		//both camera direction and camera plane must be rotated
		pmlx->pl.oldDirX = pmlx->pl.dirX;
		pmlx->pl.dirX = pmlx->pl.dirX * cos(pmlx->pl.rotSpeed) - pmlx->pl.dirY * sin(pmlx->pl.rotSpeed);
		pmlx->pl.dirY = pmlx->pl.oldDirX * sin(pmlx->pl.rotSpeed) + pmlx->pl.dirY * cos(pmlx->pl.rotSpeed);
		pmlx->pl.oldPlaneX = pmlx->pl.planeX;
		pmlx->pl.planeX = pmlx->pl.planeX * cos(pmlx->pl.rotSpeed) - pmlx->pl.planeY * sin(pmlx->pl.rotSpeed);
		pmlx->pl.planeY = pmlx->pl.oldPlaneX * sin(pmlx->pl.rotSpeed) + pmlx->pl.planeY * cos(pmlx->pl.rotSpeed);
	}
	if (key == D_KEY_L)//D
	{
		//both camera direction and camera plane must be rotated
		pmlx->pl.oldDirX = pmlx->pl.dirX;
		pmlx->pl.dirX = pmlx->pl.dirX * cos(-pmlx->pl.rotSpeed) - pmlx->pl.dirY * sin(-pmlx->pl.rotSpeed);
		pmlx->pl.dirY = pmlx->pl.oldDirX * sin(-pmlx->pl.rotSpeed) + pmlx->pl.dirY * cos(-pmlx->pl.rotSpeed);
		pmlx->pl.oldPlaneX = pmlx->pl.planeX;
		pmlx->pl.planeX = pmlx->pl.planeX * cos(-pmlx->pl.rotSpeed) - pmlx->pl.planeY * sin(-pmlx->pl.rotSpeed);
		pmlx->pl.planeY = pmlx->pl.oldPlaneX * sin(-pmlx->pl.rotSpeed) + pmlx->pl.planeY * cos(-pmlx->pl.rotSpeed);
	}
	main_loop(pmlx);
	return(0);
}