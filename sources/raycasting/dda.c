/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:49:40 by bemoreau          #+#    #+#             */
/*   Updated: 2020/08/28 12:52:17 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_ray *ray, t_pmlx *pmlx)
{
	while (ray->hit == 0)
	{
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			pmlx->pl.mapX += pmlx->pl.stepX;
			ray->side = 0;
			pmlx->tex.texNum = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			pmlx->pl.mapY += pmlx->pl.stepY;
			ray->side = 1;
			pmlx->tex.texNum = 1;
		}
		if (pmlx->s.map[pmlx->pl.mapX][pmlx->pl.mapY] > 0)
			ray->hit = 1;
	}
	if (pmlx->tex.texNum == 0 && pmlx->pl.posX > pmlx->pl.mapX)
		pmlx->tex.texNum = 2;
	else if (pmlx->tex.texNum && pmlx->pl.posY > pmlx->pl.mapY)
		pmlx->tex.texNum = 3;
}

void	init_dda(t_ray *ray, t_pmlx *pmlx)
{
	if (ray->rayDirX < 0)
	{
		pmlx->pl.stepX = -1;
		ray->sideDistX = (pmlx->pl.posX - pmlx->pl.mapX) * ray->deltaDistX;
	}
	else
	{
		pmlx->pl.stepX = 1;
		ray->sideDistX = (pmlx->pl.mapX + 1.0 - \
		pmlx->pl.posX) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		pmlx->pl.stepY = -1;
		ray->sideDistY = (pmlx->pl.posY - pmlx->pl.mapY) * ray->deltaDistY;
	}
	else
	{
		pmlx->pl.stepY = 1;
		ray->sideDistY = (pmlx->pl.mapY + 1.0 - pmlx->pl.posY) *\
		ray->deltaDistY;
	}
	dda(ray, pmlx);
}

void	init_loop(t_ray *ray, t_pmlx *pmlx, int x)
{
	ray->cameraX = 2 * x / (double)pmlx->s.R.x - 1;
	ray->rayDirX = pmlx->pl.dirX + pmlx->pl.planeX * ray->cameraX;
	ray->rayDirY = pmlx->pl.dirY + pmlx->pl.planeY * ray->cameraX;
	pmlx->pl.mapX = (int)pmlx->pl.posX;
	pmlx->pl.mapY = (int)pmlx->pl.posY;
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);
	ray->hit = 0;
	init_dda(ray, pmlx);
}
