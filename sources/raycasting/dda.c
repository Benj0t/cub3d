/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bemoreau <bemoreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 12:49:40 by bemoreau          #+#    #+#             */
/*   Updated: 2020/09/03 16:49:21 by bemoreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dda(t_ray *ray, t_pmlx *pmlx)
{
	while (ray->hit == 0)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			pmlx->pl.mapx += pmlx->pl.stepx;
			ray->side = 0;
			pmlx->tex.texnum = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			pmlx->pl.mapy += pmlx->pl.stepy;
			ray->side = 1;
			pmlx->tex.texnum = 1;
		}
		if (pmlx->s.map[pmlx->pl.mapx][pmlx->pl.mapy] > 0)
			ray->hit = 1;
	}
	if (pmlx->tex.texnum == 0 && pmlx->pl.posx > pmlx->pl.mapx)
		pmlx->tex.texnum = 2;
	else if (pmlx->tex.texnum && pmlx->pl.posy > pmlx->pl.mapy)
		pmlx->tex.texnum = 3;
}

void	init_dda(t_ray *ray, t_pmlx *pmlx)
{
	if (ray->raydirx < 0)
	{
		pmlx->pl.stepx = -1;
		ray->sidedistx = (pmlx->pl.posx - pmlx->pl.mapx) * ray->deltadistx;
	}
	else
	{
		pmlx->pl.stepx = 1;
		ray->sidedistx = (pmlx->pl.mapx + 1.0 - \
		pmlx->pl.posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		pmlx->pl.stepy = -1;
		ray->sidedisty = (pmlx->pl.posy - pmlx->pl.mapy) * ray->deltadisty;
	}
	else
	{
		pmlx->pl.stepy = 1;
		ray->sidedisty = (pmlx->pl.mapy + 1.0 - pmlx->pl.posy) *\
		ray->deltadisty;
	}
	dda(ray, pmlx);
}

void	init_loop(t_ray *ray, t_pmlx *pmlx, int x)
{
	ray->camerax = 2 * x / (double)pmlx->s.r.x - 1;
	ray->raydirx = pmlx->pl.dirx + pmlx->pl.planex * ray->camerax;
	ray->raydiry = pmlx->pl.diry + pmlx->pl.planey * ray->camerax;
	pmlx->pl.mapx = (int)pmlx->pl.posx;
	pmlx->pl.mapy = (int)pmlx->pl.posy;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
	ray->hit = 0;
	init_dda(ray, pmlx);
}
