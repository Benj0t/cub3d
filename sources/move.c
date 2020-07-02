#include "../includes/cub3d.h"

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
{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,5,1},
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};

void    forward(t_pmlx *pmlx)
{
    if(map[(int)(pmlx->pl.posX + pmlx->pl.dirX * pmlx->pl.moveSpeed)][(int)pmlx->pl.posY] == 0)
		pmlx->pl.posX += pmlx->pl.dirX * pmlx->pl.moveSpeed;
	if(map[(int)pmlx->pl.posX][(int)(pmlx->pl.posY + pmlx->pl.dirY * pmlx->pl.moveSpeed)] == 0)
		pmlx->pl.posY += pmlx->pl.dirY * pmlx->pl.moveSpeed;
}

void    downward(t_pmlx *pmlx)
{
	if(map[(int)(pmlx->pl.posX - pmlx->pl.dirX * pmlx->pl.moveSpeed)][(int)pmlx->pl.posY] == 0)
		pmlx->pl.posX -= pmlx->pl.dirX * pmlx->pl.moveSpeed;
	if(map[(int)pmlx->pl.posX][(int)(pmlx->pl.posY - pmlx->pl.dirY * pmlx->pl.moveSpeed)] == 0)
		pmlx->pl.posY -= pmlx->pl.dirY * pmlx->pl.moveSpeed;
}

void    mv_left(t_pmlx *pmlx)
{
	//both camera direction and camera plane must be rotated
	pmlx->pl.oldDirX = pmlx->pl.dirX;
	pmlx->pl.dirX = pmlx->pl.dirX * cos(pmlx->pl.rotSpeed) - pmlx->pl.dirY * sin(pmlx->pl.rotSpeed);
	pmlx->pl.dirY = pmlx->pl.oldDirX * sin(pmlx->pl.rotSpeed) + pmlx->pl.dirY * cos(pmlx->pl.rotSpeed);
	pmlx->pl.oldPlaneX = pmlx->pl.planeX;
	pmlx->pl.planeX = pmlx->pl.planeX * cos(pmlx->pl.rotSpeed) - pmlx->pl.planeY * sin(pmlx->pl.rotSpeed);
	pmlx->pl.planeY = pmlx->pl.oldPlaneX * sin(pmlx->pl.rotSpeed) + pmlx->pl.planeY * cos(pmlx->pl.rotSpeed);
}

void    mv_right(t_pmlx *pmlx)
{
    //both camera direction and camera plane must be rotated
	pmlx->pl.oldDirX = pmlx->pl.dirX;
	pmlx->pl.dirX = pmlx->pl.dirX * cos(-pmlx->pl.rotSpeed) - pmlx->pl.dirY * sin(-pmlx->pl.rotSpeed);
	pmlx->pl.dirY = pmlx->pl.oldDirX * sin(-pmlx->pl.rotSpeed) + pmlx->pl.dirY * cos(-pmlx->pl.rotSpeed);
	pmlx->pl.oldPlaneX = pmlx->pl.planeX;
	pmlx->pl.planeX = pmlx->pl.planeX * cos(-pmlx->pl.rotSpeed) - pmlx->pl.planeY * sin(-pmlx->pl.rotSpeed);
	pmlx->pl.planeY = pmlx->pl.oldPlaneX * sin(-pmlx->pl.rotSpeed) + pmlx->pl.planeY * cos(-pmlx->pl.rotSpeed);
}